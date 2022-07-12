#ifndef CRYPTO_H
#define CRYPTO_H

#include <QString>

class Crypto
{
public:
    QString paras[7];

public:
    Crypto();
    Crypto(QString*);
    //AES部分
    //注意事项：ECB模式不需要iv，密钥长度为16、24、32byte
    //        CBC模式需要iv，长度为16、24、32byte
    //        如果加密数据长度不为16的倍数，则先填充再加密，cbc下可以指定加密长度加密，如果不是16的倍数，会默认填充，也可以自己填充后再加密；
    //        但是ecb模式一次只能加密16Byte，所以必须先填充再加密
    bool AES_ECB_ENCRYPT(QString src,QString dest,QString userkey);
    bool AES_ECB_DECRYPT(QString src,QString dest,QString userkey);
    bool AES_CBC_ENCRYPT(QString src,QString dest,QString iv,QString userkey);
    bool AES_CBC_DECRYPT(QString src,QString dest,QString iv,QString userkey);

    //DES部分
    //注意事项：ECB模式不需要iv，密钥长度只能为8byte
    //         CBC模式需要iv，长度为8byte
    //         如果加密数据长度不为8的倍数，则先填充再加密，cbc下可以指定加密长度加密，如果不是16的倍数，会默认填充，也可以自己填充后再加密；
    //         但是ecb模式一次只能加密16Byte，所以必须先填充再加密
    bool DES_ECB_ENCRYPT(QString src,QString dest,QString userkey);
    bool DES_ECB_DECRYPT(QString src,QString dest,QString userkey);
    bool DES_CBC_ENCRYPT(QString s,QString d,QString i,QString u);
    bool DES_CBC_DECRYPT(QString s,QString d,QString i,QString u);
    //void DES_CBC_ENCRYPT();
    //void DES_CBC_DECRYPT();

    //RSA签名部分
    bool RSA_SIGN(QString priv,QString srcfile);
    bool RSA_VERIFY(QString cert,QString srcfile,QString signfile);
};

#endif // CRYPTO_H
