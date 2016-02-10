// Copyright © 2016 ABBI Ltd. <https://abbi.io> All rights reserved.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#import <Foundation/Foundation.h>

/**
* ABBI class manages the execution of ABBI SDK.
* Navigate to https://console.abbi.io to Register/Login and Manage Your Promotions
* For support, drop us an email at Support@abbi.io
*/
@interface ABBI : NSObject

/** Starts ABBI SDK.
 *
 * @param appId The Application Id provided by ABBI
 * @param appSecretKey The Application Secret key provided by ABBI
 * 
 * To get your Application Id and Application Secret key, login to Abbi console at https://console.abbi.io
 * and click the settings icon near your Application Name. You can find more info here - https://abbi.zendesk.com/hc
 */
+(void) start: (NSString*) appId withSecretKey: (NSString*) appSecretKey;

//
/** Utility function for remote sessions with ABBI support team.
 *
 * @param n Will be given by ABBI support team when needed
 */
+(void) setFlag: (int) n;

@end
