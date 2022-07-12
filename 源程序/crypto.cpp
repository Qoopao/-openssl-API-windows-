#include "crypto.h"
#include <openssl/aes.h>
#include <openssl/des.h>
#include <QByteArray>
#include <QString>
#include <stdio.h>
#include <QDebug>
#include <QTextCodec>
#include <QFile>
#include <QFileInfo>
#include "util.h"
#include <openssl/sha.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>


using namespace std;

//本文件加密用
Crypto::Crypto()
{

}


bool Crypto::AES_CBC_ENCRYPT(QString s,QString d,QString i,QString u){
    QByteArray iv=i.toLocal8Bit();
    QByteArray userkey=u.toLocal8Bit();
    //QByteArray iv=i.toUtf8().data();之后再memcpy到一个unsigned char的数组里 是行不通的，猜测可能是因为转换过程中长度的问题，所以访问到内存中的iv之后前面一部分相同，后面不同，导致解密失败

    if(!(userkey.size()==16||userkey.size()==24||userkey.size()==32)){
        //如果密钥长度不是16/24/32字节，或者初始iv不是16字节，返回参数非法
        qDebug() << R"(密钥长度不对)"<<userkey.size();
        return false;
    }
    if(!(iv.size()==0||iv.size()==16)){
        qDebug() << R"(向量长度不对)"<<i.size();
        return false;
    }

    //生成AESkey结构
    AES_KEY enkey;
    unsigned char ukb[userkey.size()];
    memcpy(ukb,userkey,sizeof(ukb));
    if(AES_set_encrypt_key((const unsigned char*)userkey.data(),userkey.size()*8,&enkey)!=0){
        qDebug() << R"(设置密钥结构错误)";
        return false;
    }

    util* tool=new util();
    QByteArray data;                //存储从文件中读取的数据的字节数组
    if(!tool->fileread(s,data)){
        return false;
    }

    unsigned char indata[data.size()%16==0?data.size():(data.size()/16)*16+16];  //作为加密函数的输入
    unsigned char outdata[data.size()%16==0?data.size():(data.size()/16)*16+16]; //作为加密函数的输出
    memset(indata,0,sizeof(indata));    //zeropadding
    memcpy(indata,data,data.size());


    qDebug()<<"data.size()"<<data.size();
    qDebug()<<"-----------------------1 before encrypt--------------------------------";
    for(int i=0;i<32;i++){
        qDebug()<<indata[i];
    }
    unsigned char tmpiv[16];
    memcpy(tmpiv,iv,sizeof(tmpiv));

    //如果第三个参数的长度不是16的倍数，会自动填充，填充方式未知，但是也可以自己手动填充
    AES_cbc_encrypt(indata,outdata,sizeof(indata),&enkey,tmpiv,AES_ENCRYPT);


    qDebug()<<"-----------------------1 after encrypt--------------------------------";
    for(int i=0;i<32;i++){
        qDebug()<<outdata[i];
    }

    if(!tool->filewrite(d+"/AES_cbc_en",outdata,sizeof(outdata))){
        return false;
    }
    return true;
}

bool Crypto::AES_CBC_DECRYPT(QString s,QString d,QString i,QString u){
    QByteArray iv=i.toLocal8Bit();
    QByteArray userkey=u.toLocal8Bit();
    if(!(userkey.size()==16||userkey.size()==24||userkey.size()==32)){
        //如果密钥长度不是16/24/32字节，或者初始iv不是16字节，返回参数非法
        qDebug() << R"(密钥长度不对)"<<userkey.size();
        return false;
    }
    if(!(iv.size()==0||iv.size()==16)){
        qDebug() << R"(向量长度不对)"<<i.size();
        return false;
    }

    AES_KEY dekey;
    unsigned char ukb[userkey.size()];
    memcpy(ukb,userkey,sizeof(ukb));
    if(AES_set_decrypt_key(ukb,sizeof(ukb)*8,&dekey)!=0){
        qDebug() << R"(设置密钥结构错误)";
        return false;
    }

    util* tool=new util();
    QByteArray data;                //存储从文件中读取的数据的字节数组
    if(!tool->fileread(s,data)){
        return false;
    }

    unsigned char indata[data.size()];  //作为解密函数的输入
    unsigned char outdata[data.size()]; //作为解密函数的输出
    memcpy(indata,data,sizeof(indata));

    unsigned char tmpiv[16];
    memcpy(tmpiv,iv,sizeof(tmpiv));

    qDebug()<<"data size()"<<data.size();
    qDebug()<<"-----------------------2 before encrypt--------------------------------";
    for(int i=0;i<32;i++){
        qDebug()<<indata[i];
    }

    AES_cbc_encrypt(indata,outdata,sizeof(indata),&dekey,tmpiv,AES_DECRYPT);

    qDebug()<<"-----------------------2  after encrypt--------------------------------";
    for(int i=0;i<32;i++){
        qDebug()<<outdata[i];
    }

    if(!tool->filewrite(d+"/AES_cbc_de",outdata,sizeof(outdata))){
        return false;
    }
    return true;

}

//注意里面的AES_ecb_encrypt一次只能加密16byte，而上面的cbc模式一个函数就能加密16的倍数长数据
bool Crypto::AES_ECB_ENCRYPT(QString s,QString d,QString u){

    QByteArray userkey=u.toLocal8Bit();

    if(!(userkey.size()==16||userkey.size()==24||userkey.size()==32)){
        //如果密钥长度不是16/24/32字节,返回参数非法
        qDebug() << R"(密钥长度不对)"<<userkey.size();
        return false;
    }

    //生成AESkey结构
    AES_KEY enkey;
    unsigned char ukb[userkey.size()];
    memcpy(ukb,userkey,sizeof(ukb));
    if(AES_set_encrypt_key(ukb,userkey.size()*8,&enkey)!=0){
        qDebug() << R"(设置密钥结构错误)";
        return false;
    }

    util* tool=new util();
    QByteArray data;                //存储从文件中读取的数据的字节数组
    if(!tool->fileread(s,data)){
        return false;
    }

    unsigned char indata[data.size()%16==0?data.size():(data.size()/16)*16+16];  //作为加密函数的输入
    unsigned char outdata[data.size()%16==0?data.size():(data.size()/16)*16+16]; //作为加密函数的输出
    memset(indata,0,sizeof(indata));    //zeropadding
    memcpy(indata,data,data.size());

    int times=data.size()%16==0?data.size()/16:(data.size()/16)+1;//加密的次数
    for(int i=0;i<times;i++){
        AES_ecb_encrypt(indata+16*i,outdata+16*i,&enkey,AES_ENCRYPT);
    }


    if(!tool->filewrite(d+"/AES_ecb_en",outdata,sizeof(outdata))){
        return false;
    }
    return true;
}

bool Crypto::AES_ECB_DECRYPT(QString s,QString d,QString u){


    QByteArray userkey=u.toLocal8Bit();
    if(!(userkey.size()==16||userkey.size()==24||userkey.size()==32)){
        //如果密钥长度不是16/24/32字节
        qDebug() << R"(密钥长度不对)"<<userkey.size();
        return false;
    }


    AES_KEY dekey;
    unsigned char ukb[userkey.size()];
    memcpy(ukb,userkey,sizeof(ukb));
    if(AES_set_decrypt_key(ukb,sizeof(ukb)*8,&dekey)!=0){
        qDebug() << R"(设置密钥结构错误)";
        return false;
    }

    util* tool=new util();
    QByteArray data;                //存储从文件中读取的数据的字节数组
    if(!tool->fileread(s,data)){
        return false;
    }

    unsigned char indata[data.size()];  //作为解密函数的输入
    unsigned char outdata[data.size()]; //作为解密函数的输出
    memcpy(indata,data,sizeof(indata));

    int times=data.size()/16;//解密的次数
    for(int i=0;i<times;i++){
        AES_ecb_encrypt(indata+16*i,outdata+16*i,&dekey,AES_DECRYPT);
    }

    if(!tool->filewrite(d+"/AES_ecb_de",outdata,sizeof(outdata))){
        return false;
    }
    return true;

}

//DES_set_key_unchecked()这里不能用check(),密钥没通过检验就会设置失败
bool Crypto::DES_ECB_ENCRYPT(QString s,QString d,QString u){
    QByteArray userkey=u.toLocal8Bit();

    if(userkey.size()!=8){
        //如果密钥长度不是8字节
        qDebug() << R"(密钥长度不对)"<<userkey.size();
        return false;
    }

    //生成DES密钥结构
    DES_cblock key;
    memcpy(key,userkey,sizeof(key));
    DES_key_schedule schedule;

    //check that the key passed is of odd parity and is not a week or semi-weak key.
    //If the parity is wrong, then -1 is returned.
    //If the key is a weak key, then -2 is returned.
    //If an error is returned, the key schedule is not generated. 0 is returned.
    DES_set_key_unchecked(&key,&schedule);



    util* tool=new util();
    QByteArray data;                //存储从文件中读取的数据的字节数组
    if(!tool->fileread(s,data)){
        return false;
    }

    unsigned char indata[data.size()%8==0?data.size():(data.size()/8)*8+8];  //作为加密函数的输入
    unsigned char outdata[data.size()%8==0?data.size():(data.size()/8)*8+8]; //作为加密函数的输出
    memset(indata,0,sizeof(indata));    //zeropadding
    memcpy(indata,data,data.size());

    qDebug()<<"1从文件中读取的数据------------------------------------------------------------ ";
    for(int i=0;i<sizeof(indata);i++){
        qDebug()<<" "<<indata[i];
    }

    int times=data.size()%8==0?data.size()/8:(data.size()/8)+1;//加密的次数
    for(int i=0;i<times;i++){
        DES_cblock inpart;
        DES_cblock outpart;
        memcpy(inpart,indata+i*8,sizeof(inpart));
        DES_ecb_encrypt(&inpart,&outpart,&schedule,DES_ENCRYPT);
        memcpy(outdata+i*8,outpart,sizeof(outpart));
    }

    qDebug()<<"1加密后的数据outdata------------------------------------------------------------ ";
    for(int i=0;i<sizeof(outdata);i++){
        qDebug()<<" "<<outdata[i];
    }


    if(!tool->filewrite(d+"/DES_ecb_en",outdata,sizeof(outdata))){
        return false;
    }
    return true;
}

bool Crypto::DES_ECB_DECRYPT(QString s,QString d,QString u){
    QByteArray userkey=u.toLocal8Bit();

    if(userkey.size()!=8){
        //如果密钥长度不是8字节
        qDebug() << R"(密钥长度不对)"<<userkey.size();
        return false;
    }

    //生成DES密钥结构
    DES_cblock key;
    memcpy(key,userkey,sizeof(key));
    DES_key_schedule schedule;

    //check that the key passed is of odd parity and is not a week or semi-weak key.
    //If the parity is wrong, then -1 is returned.
    //If the key is a weak key, then -2 is returned.
    //If an error is returned, the key schedule is not generated. 0 is returned.
    DES_set_key_unchecked(&key,&schedule);



    util* tool=new util();
    QByteArray data;                //存储从文件中读取的数据的字节数组
    if(!tool->fileread(s,data)){
        return false;
    }

    unsigned char indata[data.size()];  //作为解密函数的输入
    unsigned char outdata[data.size()]; //作为解密函数的输出
    memset(indata,0,sizeof(indata));    //zeropadding
    memcpy(indata,data,data.size());

    qDebug()<<"2加密前的数据indata------------------------------------------------------------ ";
    for(int i=0;i<sizeof(indata);i++){
        qDebug()<<" "<<indata[i];
    }

    int times=data.size()%8==0?data.size()/8:(data.size()/8)+1;//jie密的次数
    for(int i=0;i<times;i++){
        DES_cblock inpart;
        DES_cblock outpart;
        memcpy(inpart,indata+i*8,sizeof(inpart));
        DES_ecb_encrypt(&inpart,&outpart,&schedule,DES_DECRYPT);
        memcpy(outdata+i*8,outpart,sizeof(outpart));
    }

    qDebug()<<"2解密后的数据outdata------------------------------------------------------------ ";
    for(int i=0;i<sizeof(outdata);i++){
        qDebug()<<" "<<outdata[i];
    }


    if(!tool->filewrite(d+"/DES_ecb_de",outdata,sizeof(outdata))){
        return false;
    }
    return true;
}

bool Crypto::DES_CBC_ENCRYPT(QString s,QString d,QString i,QString u){
    QByteArray userkey=u.toLocal8Bit();
    QByteArray iv=i.toLocal8Bit();
    if(userkey.size()!=8){
        //如果密钥长度不是8字节
        qDebug() << R"(密钥长度不对)"<<userkey.size();
        return false;
    }
    if(iv.size()!=8){
        //如果偏移量长度不是8字节
        qDebug() << R"(iv长度不对)"<<iv.size();
        return false;
    }

    //生成DES密钥结构
    DES_cblock key;
    memcpy(key,userkey,sizeof(key));
    DES_key_schedule schedule;

    //check that the key passed is of odd parity and is not a week or semi-weak key.
    //If the parity is wrong, then -1 is returned.
    //If the key is a weak key, then -2 is returned.
    //If an error is returned, the key schedule is not generated. 0 is returned.
    DES_set_key_unchecked(&key,&schedule);



    util* tool=new util();
    QByteArray data;                //存储从文件中读取的数据的字节数组
    if(!tool->fileread(s,data)){
        return false;
    }

    unsigned char indata[data.size()%8==0?data.size():(data.size()/8)*8+8];  //作为加密函数的输入
    unsigned char outdata[data.size()%8==0?data.size():(data.size()/8)*8+8]; //作为加密函数的输出
    memset(indata,0,sizeof(indata));    //zeropadding
    memcpy(indata,data,data.size());

    qDebug()<<"1从文件中读取的数据------------------------------------------------------------ ";
    for(int i=0;i<sizeof(indata);i++){
        qDebug()<<" "<<indata[i];
    }

    DES_cblock ivec;
    memcpy(ivec,iv,sizeof(ivec));
    int times=data.size()%8==0?data.size()/8:(data.size()/8)+1;//加密的次数
    for(int i=0;i<times;i++){
        unsigned char inpart[8];
        unsigned char outpart[8];
        memcpy(inpart,indata+i*8,sizeof(inpart));
        DES_ncbc_encrypt(inpart,outpart,8,&schedule,&ivec,DES_ENCRYPT);
        memcpy(outdata+i*8,outpart,sizeof(outpart));
    }

    qDebug()<<"1加密后的数据outdata------------------------------------------------------------ ";
    for(int i=0;i<sizeof(outdata);i++){
        qDebug()<<" "<<outdata[i];
    }


    if(!tool->filewrite(d+"/DES_cbc_en",outdata,sizeof(outdata))){
        return false;
    }
    return true;
}

bool Crypto::DES_CBC_DECRYPT(QString s,QString d,QString i,QString u){
    QByteArray userkey=u.toLocal8Bit();
    QByteArray iv=i.toLocal8Bit();

    if(userkey.size()!=8){
        //如果密钥长度不是8字节
        qDebug() << R"(密钥长度不对)"<<userkey.size();
        return false;
    }

    if(iv.size()!=8){
        //iv
        qDebug() << R"(iv长度不对)"<<iv.size();
        return false;
    }

    //生成DES密钥结构
    DES_cblock key;
    memcpy(key,userkey,sizeof(key));
    DES_key_schedule schedule;

    //check that the key passed is of odd parity and is not a week or semi-weak key.
    //If the parity is wrong, then -1 is returned.
    //If the key is a weak key, then -2 is returned.
    //If an error is returned, the key schedule is not generated. 0 is returned.
    DES_set_key_unchecked(&key,&schedule);



    util* tool=new util();
    QByteArray data;                //存储从文件中读取的数据的字节数组
    if(!tool->fileread(s,data)){
        return false;
    }

    unsigned char indata[data.size()];  //作为解密函数的输入
    unsigned char outdata[data.size()]; //作为解密函数的输出
    memset(indata,0,sizeof(indata));    //zeropadding
    memcpy(indata,data,data.size());

    qDebug()<<"2加密前的数据indata------------------------------------------------------------ ";
    for(int i=0;i<sizeof(indata);i++){
        qDebug()<<" "<<indata[i];
    }

    DES_cblock ivec;
    memcpy(ivec,iv,sizeof(ivec));
    int times=data.size()%8==0?data.size()/8:(data.size()/8)+1;//jie密的次数
    for(int i=0;i<times;i++){
        unsigned char inpart[8];
        unsigned char outpart[8];
        memcpy(inpart,indata+i*8,sizeof(inpart));
        DES_ncbc_encrypt(inpart,outpart,8,&schedule,&ivec,DES_DECRYPT);
        memcpy(outdata+i*8,outpart,sizeof(outpart));
    }

    qDebug()<<"2解密后的数据outdata------------------------------------------------------------ ";
    for(int i=0;i<sizeof(outdata);i++){
        qDebug()<<" "<<outdata[i];
    }


    if(!tool->filewrite(d+"/DES_cbc_de",outdata,sizeof(outdata))){
        return false;
    }
    return true;
}

bool Crypto::RSA_SIGN(QString priv,QString srcfile){

    QByteArray srcdata;//存放文件中的字节数据
    unsigned char hash256[32];//存放sha256哈希之后的结果

    //读文件生成哈希
    util* tool=new util();
    if(!tool->fileread(srcfile,srcdata)){
        return false;
    }

    unsigned char source[srcdata.size()];

    memcpy(source,srcdata,sizeof(source));
    SHA256(source,srcdata.size(),hash256);//计算文件的hash

    //读取私钥文件生成RSA结构
    QByteArray tmp=priv.toLocal8Bit();      //首先将传入参数的私钥文件路径存入字节数组
    char privname[tmp.size()];              //将字节数组拷贝到fopen函数需要的参数类型的数组
    memcpy(privname,tmp,sizeof(privname));
    RSA *rsa_pri_key = RSA_new();
    FILE *fp = NULL;
    fp = fopen(privname, "rt");
    if((rsa_pri_key=PEM_read_RSAPrivateKey(fp,NULL,NULL,NULL)) == NULL)
    {
        RSA_free(rsa_pri_key);
        fclose(fp);
        qDebug()<<"PEM_read_RSAPrivateKey error\r\n";
        return false;
    }


    //签名
    unsigned char sign[RSA_size(rsa_pri_key)];
    //unsigned int signlen=0;
    //if(RSA_sign(NID_sha256,hash256,sizeof(hash256),sign,&signlen,rsa_pri_key)!=1){
    //   qDebug()<<"失败";
    //    return false;
    //}

    //注意这里的加密函数第一个参数是明文长度
    RSA_private_encrypt(sizeof(hash256),hash256,sign,rsa_pri_key,RSA_PKCS1_PADDING);

    qDebug()<<"-----------------------------计算的hash值--------------------------------------";
    for(int i=0;i<sizeof(hash256);i++){
        qDebug()<<hash256[i];
    }

    qDebug()<<"-----------------------------加密的hash值--------------------------------------";
    for(int i=0;i<sizeof(sign);i++){
        qDebug()<<sign[i];
    }
    if(!tool->filewrite(srcfile+".sign",sign,sizeof(sign))){
        return false;
    }
    return true;

}

bool Crypto::RSA_VERIFY(QString cert,QString srcfile,QString signfile){
    QByteArray hashtmp;
    //读.sign文件存入该数组
    util* tool=new util();
    if(!tool->fileread(signfile,hashtmp)){
        return false;
    }
    unsigned char readhash[hashtmp.size()];
    memcpy(readhash,hashtmp,sizeof(readhash));

    //读原文件生成摘要
    QByteArray srcdata; //原文件的字节数据
    if(!tool->fileread(srcfile,srcdata)){
        return false;
    }
    unsigned char calhash[32];
    unsigned char source[srcdata.size()];
    memcpy(source,srcdata,sizeof(source));
    SHA256(source,srcdata.size(),calhash);
    qDebug()<<"-----------------------------对文件计算的的hash值--------------------------------------";
    for(int i=0;i<sizeof(calhash);i++){
        qDebug()<<calhash[i];
    }


    //获取RSA 公钥结构
    QByteArray certtmp=cert.toLocal8Bit();
    char pub[certtmp.size()];
    memcpy(pub,certtmp,sizeof(pub));

    RSA *rsa_pub_key = RSA_new();
    FILE *fp = NULL;
    fp = fopen(pub, "rt");
    if( fp == NULL )
    {
        RSA_free(rsa_pub_key);
        qDebug()<<"PEM_read_RSAPublicKey error\r\n";
        return false;
    }

    if((rsa_pub_key=PEM_read_RSA_PUBKEY(fp,NULL,NULL,NULL))==NULL)
    {
        RSA_free(rsa_pub_key);
        fclose(fp);
        qDebug()<<"PEM_read_RSA_PUBKEY error\r\n";
        return false;
    }
    fclose(fp);


    //注意这里的解密函数第一个参数是密文长度，即私钥长度
    unsigned char dehash[sizeof(readhash)];
    RSA_public_decrypt(RSA_size(rsa_pub_key),readhash,dehash,rsa_pub_key,RSA_PKCS1_PADDING);
    qDebug()<<"-----------------------------解密的hash--------------------------------------";
    for(int i=0;i<sizeof(dehash);i++){
        qDebug()<<dehash[i];
    }
    //int iRet = RSA_verify(NID_sha256, calhash, 32, readhash, 32, rsa_pub_key);
    //if(1 != iRet)
    //{
    //    RSA_free(rsa_pub_key);
    //    qDebug()<<"验证失败";
    //    return false;
    //}
    //else{
    //    qDebug()<<"验证成功";
    //}

    //只需要检查数据的前32个字节(hash数据)即可
    for(int i=0;i<32;i++){
        if(dehash[i]!=calhash[i])
            return false;
    }
    return true;
}

