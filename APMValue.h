//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

#import "NSCopying.h"

@class NSString;

@interface APMValue : NSObject <NSCopying>
{
    id _value;
    int _valueType;
}

+ (id)valueFromObject:(id)arg1;
@property(readonly, nonatomic) int valueType; // @synthesize valueType=_valueType;
- (void).cxx_destruct;
- (unsigned int)hash;
- (BOOL)isEqual:(id)arg1;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (id)description;
@property(readonly, nonatomic) NSString *stringValue;
@property(readonly, nonatomic) BOOL isString;
@property(readonly, nonatomic) long long int64Value;
@property(readonly, nonatomic) BOOL isInt64;
@property(readonly, nonatomic) double doubleValue;
@property(readonly, nonatomic) BOOL isDouble;
- (id)initWithValueType:(int)arg1 value:(id)arg2;
- (id)initWithString:(id)arg1;
- (id)initWithInt64:(long long)arg1;
- (id)initWithDouble:(double)arg1;

@end

