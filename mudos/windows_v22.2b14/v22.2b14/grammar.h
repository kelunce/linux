typedef union

{
    POINTER_INT pointer_int;
    int number;
    float real;
    char *string;
    int type;
    struct { short num_arg; char flags; } argument;
    ident_hash_elem_t *ihe;
    parse_node_t *node;
    function_context_t *contextp;
    struct {
	parse_node_t *node;
        char num;
    } decl; /* 5 */
    struct {
	char num_local;
	char max_num_locals; 
	short context; 
	short save_current_type; 
	short save_exact_types;
    } func_block; /* 8 */
} YYSTYPE;
#define	L_STRING	258
#define	L_NUMBER	259
#define	L_REAL	260
#define	L_BASIC_TYPE	261
#define	L_TYPE_MODIFIER	262
#define	L_DEFINED_NAME	263
#define	L_IDENTIFIER	264
#define	L_EFUN	265
#define	L_INC	266
#define	L_DEC	267
#define	L_ASSIGN	268
#define	L_LAND	269
#define	L_LOR	270
#define	L_LSH	271
#define	L_RSH	272
#define	L_ORDER	273
#define	L_NOT	274
#define	L_IF	275
#define	L_ELSE	276
#define	L_SWITCH	277
#define	L_CASE	278
#define	L_DEFAULT	279
#define	L_RANGE	280
#define	L_DOT_DOT_DOT	281
#define	L_WHILE	282
#define	L_DO	283
#define	L_FOR	284
#define	L_FOREACH	285
#define	L_IN	286
#define	L_BREAK	287
#define	L_CONTINUE	288
#define	L_RETURN	289
#define	L_ARROW	290
#define	L_INHERIT	291
#define	L_COLON_COLON	292
#define	L_ARRAY_OPEN	293
#define	L_MAPPING_OPEN	294
#define	L_FUNCTION_OPEN	295
#define	L_NEW_FUNCTION_OPEN	296
#define	L_SSCANF	297
#define	L_CATCH	298
#define	L_TREE	299
#define	L_ARRAY	300
#define	L_REF	301
#define	L_PARSE_COMMAND	302
#define	L_TIME_EXPRESSION	303
#define	L_CLASS	304
#define	L_NEW	305
#define	L_PARAMETER	306
#define	LOWER_THAN_ELSE	307
#define	L_EQ	308
#define	L_NE	309


extern YYSTYPE yylval;
