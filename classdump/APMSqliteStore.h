//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSMutableDictionary, NSString;

@interface APMSqliteStore : NSObject
{
    struct sqlite3 *_sqliteHandle;
    NSMutableDictionary *_statementCache;
    const char *_queueLabel;
    NSString *_databasePath;
}

@property(readonly, nonatomic) NSString *databasePath; // @synthesize databasePath=_databasePath;
- (void).cxx_destruct;
- (void)setDatabaseError:(id *)arg1 operation:(id)arg2;
- (id)monitorContextForDatabaseOperation:(id)arg1;
- (id)errorDescriptionForDatabaseOperation:(id)arg1;
- (id)lastErrorMessage;
- (BOOL)bindValues:(id)arg1 toStatement:(struct sqlite3_stmt *)arg2 error:(id *)arg3;
- (struct sqlite3_stmt *)updateStatementForRecord:(id)arg1 inTableWithName:(id)arg2 columnName:(id)arg3 columnValue:(id)arg4 error:(id *)arg5;
- (struct sqlite3_stmt *)upsertStatementForRecord:(id)arg1 inTableWithName:(id)arg2 error:(id *)arg3;
- (id)valueAtColumn:(int)arg1 forStatement:(struct sqlite3_stmt *)arg2;
- (void)finalizeAndClearStatements;
- (void)closeDatabase;
- (BOOL)validateDatabaseWithError:(id *)arg1;
- (BOOL)openAndValidateDatabase:(id *)arg1;
- (BOOL)executeSQLStatement:(struct sqlite3_stmt *)arg1 error:(id *)arg2;
- (BOOL)executeSQL:(id)arg1 error:(id *)arg2;
- (struct sqlite3_stmt *)prepareSQL:(id)arg1 error:(id *)arg2;
- (void)cleanUpStatement:(struct sqlite3_stmt *)arg1 forQuery:(id)arg2;
- (struct sqlite3_stmt *)statementForQuery:(id)arg1 parameterValues:(id)arg2 error:(id *)arg3;
- (struct sqlite3_stmt *)statementForQuery:(id)arg1 error:(id *)arg2;
- (BOOL)rollbackTransaction;
- (BOOL)endTransaction;
- (BOOL)beginTransaction;
- (BOOL)performTransaction:(CDUnknownBlockType)arg1;
- (id)numberForQuery:(id)arg1 parameterValues:(id)arg2 error:(id *)arg3;
- (id)recordsForQuery:(id)arg1 parameterValues:(id)arg2 error:(id *)arg3 withFilter:(CDUnknownBlockType)arg4;
- (id)recordsForQuery:(id)arg1 parameterValues:(id)arg2 error:(id *)arg3;
- (BOOL)deleteAllRecordsFromTableWithName:(id)arg1 error:(id *)arg2;
- (id)deleteRecordsFromTableWithName:(id)arg1 condition:(id)arg2 parameterValues:(id)arg3 error:(id *)arg4;
- (BOOL)deleteRecordFromTableWithName:(id)arg1 columnName:(id)arg2 columnValue:(id)arg3 error:(id *)arg4;
- (BOOL)increaseColumn:(id)arg1 byValue:(long long)arg2 inTable:(id)arg3 condition:(id)arg4 parameterValues:(id)arg5 error:(id *)arg6;
- (BOOL)updateRecord:(id)arg1 inTableWithName:(id)arg2 columnName:(id)arg3 columnValue:(id)arg4 error:(id *)arg5;
- (BOOL)upsertRecord:(id)arg1 inTableWithName:(id)arg2 error:(id *)arg3;
- (id)columnInfoForTableWithName:(id)arg1 error:(id *)arg2;
- (id)columnsForTableWithName:(id)arg1 error:(id *)arg2;
- (id)rowCountForTableWithName:(id)arg1 columnName:(id)arg2 columnValue:(id)arg3 error:(id *)arg4;
- (id)rowCountForTableWithName:(id)arg1 error:(id *)arg2;
- (id)tableExists:(id)arg1 error:(id *)arg2;
- (id)validateTableWithName:(id)arg1 requiredColumnNames:(id)arg2 addOnColumns:(id)arg3 error:(id *)arg4;
- (BOOL)copyContentsFromTable:(id)arg1 toTable:(id)arg2 error:(id *)arg3;
- (BOOL)renameTable:(id)arg1 toName:(id)arg2 error:(id *)arg3;
- (BOOL)dropTableWithName:(id)arg1 error:(id *)arg2;
- (BOOL)ensureTableWithName:(id)arg1 createSQL:(id)arg2 requiredColumnNames:(id)arg3 addOnColumns:(id)arg4 error:(id *)arg5;
- (BOOL)ensureTableWithName:(id)arg1 elementaryColumnInfo:(id)arg2 addOnColumnInfo:(id)arg3 modifyColumnInfo:(id)arg4 error:(id *)arg5;
- (BOOL)ensureSchemaOfTableWithName:(id)arg1 elementaryColumnInfo:(id)arg2 addOnColumnInfo:(id)arg3 error:(id *)arg4;
- (BOOL)ensureTableWithName:(id)arg1 elementaryColumnInfo:(id)arg2 addOnColumnInfo:(id)arg3 error:(id *)arg4;
- (BOOL)closeAndDeleteDatabase;
@property(readonly, nonatomic) struct sqlite3 *sqliteHandle;
- (void)dealloc;
- (id)initWithDatabasePath:(id)arg1;

@end

