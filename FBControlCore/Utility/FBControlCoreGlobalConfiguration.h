/**
 * Copyright (c) 2015-present, Facebook, Inc.
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree. An additional grant
 * of patent rights can be found in the PATENTS file in the same directory.
 */

#import <Foundation/Foundation.h>

#import <FBControlCore/FBJSONConversion.h>

@protocol FBControlCoreLogger;

NS_ASSUME_NONNULL_BEGIN

/**
 An Environment Variable: 'FBCONTROLCORE_LOGGING' to enable logging of Informational Messages to stderr.
 */
extern NSString *const FBControlCoreStderrLogging;

/**
 An Environment Variable: 'FBCONTROLCORE_DEBUG_LOGGING' to enable logging of Debug Messages to stderr.
 */
extern NSString *const FBControlCoreDebugLogging;

/**
 Environment Globals & other derived constants.
 These values can be accessed before the Private Frameworks are loaded.
 */
@interface FBControlCoreGlobalConfiguration : NSObject <FBJSONSerializable>

/**
 A Timeout Value when waiting on events that should happen 'fast'
 */
@property (nonatomic, assign, readonly, class) NSTimeInterval fastTimeout;

/**
 A Timeout Value when waiting on events that will take some time longer than 'fast' events.
 */
@property (nonatomic, assign, readonly, class) NSTimeInterval regularTimeout;

/**
 A Timeout Value when waiting on events that will a longer period of time.
 */
@property (nonatomic, assign, readonly, class) NSTimeInterval slowTimeout;

/**
 A Description of the Current Configuration.
 */
@property (nonatomic, copy, readonly, class) NSString *description;

/**
 The default logger to send log messages to.
 */
@property (nonatomic, strong, readwrite, class) id<FBControlCoreLogger> defaultLogger;

/**
 Confirm the existence of code signatures, where relevant.
 */
@property (nonatomic, assign, readonly, class) BOOL confirmCodesignaturesAreValid;

@end

NS_ASSUME_NONNULL_END
