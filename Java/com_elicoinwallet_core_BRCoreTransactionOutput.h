/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_elicoinwallet_core_BRCoreTransactionOutput */

#ifndef _Included_com_elicoinwallet_core_BRCoreTransactionOutput
#define _Included_com_elicoinwallet_core_BRCoreTransactionOutput
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_elicoinwallet_core_BRCoreTransactionOutput
 * Method:    createTransactionOutput
 * Signature: (J[B)J
 */
JNIEXPORT jlong JNICALL Java_com_elicoinwallet_core_BRCoreTransactionOutput_createTransactionOutput
  (JNIEnv *, jclass, jlong, jbyteArray);

/*
 * Class:     com_elicoinwallet_core_BRCoreTransactionOutput
 * Method:    getAddress
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_elicoinwallet_core_BRCoreTransactionOutput_getAddress
  (JNIEnv *, jobject);

/*
 * Class:     com_elicoinwallet_core_BRCoreTransactionOutput
 * Method:    setAddress
 * Signature: (Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_com_elicoinwallet_core_BRCoreTransactionOutput_setAddress
  (JNIEnv *, jobject, jstring);

/*
 * Class:     com_elicoinwallet_core_BRCoreTransactionOutput
 * Method:    getAmount
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_com_elicoinwallet_core_BRCoreTransactionOutput_getAmount
  (JNIEnv *, jobject);

/*
 * Class:     com_elicoinwallet_core_BRCoreTransactionOutput
 * Method:    setAmount
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_elicoinwallet_core_BRCoreTransactionOutput_setAmount
  (JNIEnv *, jobject, jlong);

/*
 * Class:     com_elicoinwallet_core_BRCoreTransactionOutput
 * Method:    getScript
 * Signature: ()[B
 */
JNIEXPORT jbyteArray JNICALL Java_com_elicoinwallet_core_BRCoreTransactionOutput_getScript
  (JNIEnv *, jobject);

#ifdef __cplusplus
}
#endif
#endif
