//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@interface FIRConnectorUtils : NSObject
{
}

+ (BOOL)isUserPropertyAllowed:(id)arg1 withOrigin:(id)arg2;
+ (BOOL)shouldLogEventWithName:(id)arg1 parameters:(id)arg2;
+ (BOOL)isEventNameAllowedForListeners:(id)arg1;
+ (BOOL)isListenerOriginAllowed:(id)arg1;
+ (BOOL)isOriginAllowed:(id)arg1;
+ (id)hiddenEventNames;
+ (id)blacklistedUserPropertyPatterns;
+ (id)blacklistedUserProperties;
+ (id)blacklistedParameters;
+ (id)blacklistedEventNames;
+ (id)blacklistedOrigins;
+ (id)allowedListenerOrigins;

@end
