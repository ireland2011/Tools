//
//  NSNumber+NSNumber_CDAdd.m
//  Tools
//
//  Created by Genius on 12/06/2017.
//  Copyright © 2017 Genius. All rights reserved.
//

#import "NSNumber+NSNumber_CDAdd.h"
#import "NSString+NSString_CDAdd.h"


@implementation NSNumber (NSNumber_CDAdd)

+ (NSNumber *)numberWithString:(NSString *)string {
    NSString *str = [[string stringByTrim] lowercaseString];
    if (!str || !str.length) {
        return nil;
    }
    // special character
    static NSDictionary *dic;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        dic = @{
                @"true": @(YES),
                @"yes": @(YES),
                @"false": @(NO),
                @"no": @(NO),
                @"nil": [NSNull null],
                @"null": [NSNull null],
                @"<null>": [NSNull null],
                };
    });
    
    id num = dic[str];
    if (num) {
        if (num == [NSNull null]) return nil;
        return num;
    }
    
    // hex number
    int sign = 0;
    if ([str hasPrefix:@"0x"]) sign = 1;
    else if ([str hasPrefix:@"-0x"]) sign = -1;
    
    if (sign != 0) {
        NSScanner *scan = [NSScanner scannerWithString:str];
        unsigned num = -1;
        BOOL suc = [scan scanHexInt:&num];
        if (suc) {
            return [NSNumber numberWithLong:((long)num * sign)];
        }else {
            return nil;
        }
    }
    
    // normal number
    NSNumberFormatter *formatter = [[NSNumberFormatter alloc] init];
    [formatter setNumberStyle:NSNumberFormatterDecimalStyle];
    return [formatter numberFromString:string];
    
}

@end
