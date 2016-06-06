//
//  NSString+Encryption.h
//  EncryptionTools
//
//  Created by mdd on 16/6/2.
//  Copyright © 2016年 com.personal. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CommonCrypto/CommonCrypto.h>
#import <CommonCrypto/CommonHMAC.h>

/// 默认使用kCCOptionPKCS7Padding填充
#define kPaddingMode kCCOptionPKCS7Padding

@interface NSString (Encryption)

/**
 AES-CBC模式加密，默认模式
 @param key Hex形式，密钥支持128 192 256bit，16、24、32字节，转换为16进制字符串长度为32、48、64，长度错误将抛出异常
 @param iv 进制字符串形式；初始化向量iv为16字节。如果为nil，则初始化向量为0
 @return 加密结果为base64编码
 */
- (NSString *)aesEncryptWithHexKey:(NSString *)key hexIv:(NSString *)iv;

/**
 AES-CBC模式加密，默认模式
 @param key 密钥支持128 192 256bit，16、24、32字节，长度错误将抛出异常
 @param iv 进制字符串形式；初始化向量iv为16字节。如果为nil，则初始化向量为0
 @return 加密结果为base64编码
 */
- (NSString *)aesEncryptWithKey:(NSString *)key iv:(NSString *)iv;

/**
 AES-CBC模式加密，默认模式
 @param data 要加密的数据
 @param key 密钥支持128 192 256bit，16、24、32字节，长度错误将抛出异常
 @param iv 进制字符串形式；初始化向量iv为16字节。如果为nil，则初始化向量为0
 @return 加密结果为NSData形式
 */
- (NSData *)aesEncryptWithDataKey:(NSData *)key dataIv:(NSData *)iv;

/**
 AES-ECB模式加密
 @param key Hex形式，密钥支持128 192 256bit，16、24、32字节，转换为16进制字符串长度为32、48、64，长度错误将抛出异常
 @return 加密结果为base64编码
 */
- (NSString *)aesECBEncryptWithHexKey:(NSString *)key;

/**
 AES-ECB模式加密
 @param key 字符串形式，密钥支持128 192 256bit，16、24、32字节，长度错误将抛出异常
 @return 加密结果为base64编码
 */
- (NSString *)aesECBEncryptWithKey:(NSString *)key;

/**
 AES-ECB模式加密
 @param key 密钥支持128 192 256bit，16、24、32字节，长度错误将抛出异常
 */
- (NSData *)aesECBEncryptWithDataKey:(NSData *)key;

#pragma mark - 解密

/**
 AES-CBC模式解密，要求NSString为base64的结果
 @param key 密钥支持128 192 256bit，16、24、32字节，长度错误将抛出异常
 */
- (NSString *)aesBase64StringDecryptWithHexKey:(NSString *)key hexIv:(NSString *)iv;

+ (NSData *)aesDecryptWithData:(NSData *)data dataKey:(NSData *)key dataIv:(NSData *)iv;

@end



