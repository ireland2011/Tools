//
//  NSString+NSString_CDAdd.h
//  Tools
//
//  Created by Genius on 12/06/2017.
//  Copyright © 2017 Genius. All rights reserved.
//

#import <UIKit/UIKit.h>


NS_ASSUME_NONNULL_BEGIN


@interface NSString (NSString_CDAdd)

#pragma mark - Hash

#pragma mark - Encode and decode

#pragma mark - Drawing

/** returns the size of the string if it were rendered with the specified constraints */
- (CGSize)sizeForFont:(UIFont *)font size:(CGSize)size mode:(NSLineBreakMode)lineBreakMode;

/** returns the width of the string if it were rendered with the specified font on a single line */
- (CGFloat)widthFotFont:(UIFont *)font;

/** returns the height of the string if it were rendered with the specified constraints */
- (CGFloat)heightForFont:(UIFont *)font width:(CGFloat)width;



#pragma mark - Regular Expression

/** whether it can match regular expression */
- (BOOL)matchesRegex:(NSString *)regex options:(NSRegularExpressionOptions)options;

/** match the regular expression, and executes a given blockk using each object in the matches */
- (void)enumerateRegexMatches:(NSString *)regex
                      options:(NSRegularExpressionOptions)options
                   usingBlock:(void(^)(NSString *match, NSRange matchRange, BOOL *stop))block;

/** return a new string containing mathcing regular expressions replaced with the template string */
- (NSString *)stringByReplacingRegex:(NSString *)regex
                             options:(NSRegularExpressionOptions)options
                          withString:(NSString *)replacement;



#pragma mark - NSNumber Compatible

/** now you can use NSString as a NSNumber */
@property (readonly) char charValue;
@property (readonly) unsigned char unsignedCharValue;

@property (readonly) short shortValue;
@property (readonly) unsigned short unsignedShortValue;

@property (readonly) unsigned int unsignedIntValue;

@property (readonly) long longValue;

@property (readonly) unsigned long unsignedLongValue;
@property (readonly) unsigned long long unsignedLongLongValue;
@property (readonly) NSUInteger unsignedIntegerValue;


#pragma mark - Utilities

/** "D1178E50-2A4D-4F1F-9BD3-F6AAB00E06B1" */
+ (NSString *)stringWithUUID;

/** returns a string containing the characters in a given UTF32Char */
+ (nullable NSString *)stringWithUTF32Char:(UTF32Char)char32;

/** returns a string containing the characters in a given UTF32Char array */
+ (nullable NSString *)stringWithUTF32Char:(const UTF32Char *)char32 length:(NSUInteger)length;

/** enumerates the unicode characters(UTF-32) int the specified range of the string */
- (void)enumerateUTF32CharInRange:(NSRange)range usingBlock:(void(^)(UTF32Char char32, NSRange range, BOOL *stop))block;

/** trim black characters(space and newline) in head and tail */
- (NSString *)stringByTrim;

/** add scale modifier to the file name(without path extension). from @"name" to @"name@2x" */
- (NSString *)stringByAppendingNameScale:(CGFloat)scale;

/** add scale modifier to the file path(with path extension). from @"name.png" to @"name@2x.png" */
- (NSString *)stringByAppendingPathScale:(CGFloat)scale;

/** return the path scale */
- (CGFloat)pathScale;

/** nil, @"", @"  ", @"\n" will  returns NO; otherwise returns YES */
- (BOOL)isNotBlank;

/** return YES if the target string is contained within the receiver */
- (BOOL)containsString:(NSString *)string;

/** returns YES if the target CharacterSet is contained within the receive*/
-(BOOL)containsCharacterSet:(NSCharacterSet *)set;

/** try to parse this string and returns an "NSNumber" */
- (nullable NSNumber *)numberValue;

/** return an NSData using UTF-8 encoding */
- (nullable NSData *)dataValue;

/** returns NSMakeRange(0, self.length) */
- (NSRange)rangeOfAll;

/** returns an NSDictionary/NSArray which is decoded from receiver */
- (nullable id)jsonValueDecoded;

/** create a string from the file in main bundle(similiar to  [UIImage imageNamed:]) */
+ (nullable NSString *)stringNamed:(NSString *)name;




@end


NS_ASSUME_NONNULL_END
