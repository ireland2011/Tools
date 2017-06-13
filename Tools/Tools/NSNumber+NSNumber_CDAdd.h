//
//  NSNumber+NSNumber_CDAdd.h
//  Tools
//
//  Created by Genius on 12/06/2017.
//  Copyright © 2017 Genius. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSNumber (NSNumber_CDAdd)

/** provide a method to parse 'NSString' for 'NSNumber' 
    invalid format: @"12", @"12.345", @"-0xFF", @".23e99"
 */
+ (nullable NSNumber *)numberWithString:(NSString *)string;


@end

NS_ASSUME_NONNULL_END
