//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSMutableDictionary, NSString;

@interface FIRClearcutAccountData : NSObject
{
    NSMutableDictionary *_logSourceToWriter;
    NSString *_accountLogDirectory;
}

@property(copy, nonatomic) NSString *accountLogDirectory; // @synthesize accountLogDirectory=_accountLogDirectory;
@property(readonly, copy, nonatomic) NSMutableDictionary *logSourceToWriter; // @synthesize logSourceToWriter=_logSourceToWriter;
- (void).cxx_destruct;
- (id)filenameWithCurrentTimeInDirectory:(id)arg1;
- (void)flushWriters;
- (void)removeWriterForLogSource:(int)arg1;
- (id)writerForLogSource:(int)arg1;
- (id)initWithAccountLogDirectory:(id)arg1;

@end

