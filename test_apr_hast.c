/*
 * gcc -I/usr/include/apr-1/  -lapr-1 -ggdb3 testhash.c
 * by lichengman@163.com 2016/02/23
 * */
#include <stdio.h>
#include <string.h>
#include "apr.h"
#include "apr_pools.h"
#include "apr_hash.h"

typedef struct hase_test_base {
    apr_pool_t *pool;
    apr_hash_t *int_int_hash;
    apr_hash_t *string_int_hash;
} hash_test_t;

hash_test_t data_mng;

void init_apr_lib()
{
    /* apr_initialize
     * Setup any APR internal data structures. 
     * This MUST be the first function called for any APR library. 
     * It is safe to call apr_initialize several times as long as apr_terminate is called the same number of times.
     * */
    apr_initialize();
    
    /* 
     * apr_status_t apr_pool_create(apr_pool_t **newpool,apr_pool_t* parent)
     * Create a new pool.
     *
     * Parameters:
     * newpool  The pool we have just created.
     * parent   The parent pool. If this is NULL, the new pool is a root pool. 
     *          If it is non-NULL, the new pool will inherit all of its parent pool's attributes, except the apr_pool_t will be a sub-pool.
     * Remarks:
     * This function is thread-safe, in the sense that multiple threads can safely create subpools of the same parent pool concurrently. 
     * Similarly, a subpool can be created by one thread at the same time that another thread accesses the parent pool.
     * */
    apr_pool_create(&data_mng.pool, NULL);

    /* apr_hash_t* apr_hash_make (apr_pool_t *pool)
     * Create a hash table.
     *
     * Parameters:
     * pool The pool to allocate the hash table out of
     * Returns:
     * The hash table just created
     * */
    data_mng.int_int_hash = apr_hash_make(data_mng.pool);
    data_mng.string_int_hash = apr_hash_make(data_mng.pool);
}

void free_apr_lib()
{
    /* apr_terminate:
     * Tear down any APR internal data structures which aren't torn down automatically. 
     * apr_terminate must be called once for every call to apr_initialize() or apr_app_initialize().
     * */
    apr_terminate();
}

// insert
void int_int_hash_add(int k, int val)
{
    int *key = calloc(1, sizeof(int)); // key 会被引用, 必须维护住内存
    *key = k;
    int *value = calloc(1, sizeof(int));// value 会被引用住, 所以必须自己维护
    *value = val;
    apr_hash_set(data_mng.int_int_hash, key, sizeof(int), value);
}

// select
void int_int_hash_select(int key, int select_all)
{
    if(select_all){
        apr_hash_index_t *hi;
        void *key;
        apr_ssize_t key_len;// 使用int类型出错
        void *val;
        for (hi = apr_hash_first(data_mng.pool, data_mng.int_int_hash); hi; hi = apr_hash_next(hi)) {
            apr_hash_this(hi, &key, (apr_ssize_t *)&key_len, &val);
            fprintf(stderr, "%d --> %d\n", *(int*)key, *(int*)val);
        }
    }else{
        int *val = (int *)apr_hash_get(data_mng.int_int_hash, &key, sizeof(int));
        if(val)
            fprintf(stderr, "%d --> %d\n", key, *(int *)val);
        else
            fprintf(stderr, "can`t find key %d \n", key);
    }
}

void string_int_hash_add(char * k, int val)
{
    int *value = calloc(1, sizeof(int));// value 会被引用住, 所以必须自己维护
    *value = val;

    char *key = strdup(k);
    apr_hash_set(data_mng.string_int_hash, key, strlen(key), value);
}

void string_int_hash_select(char * key, int select_all)
{
    if(select_all){
        apr_hash_index_t *hi;
        void *key;
        apr_ssize_t key_len;// 使用int类型出错
        void *val;
        for (hi = apr_hash_first(data_mng.pool, data_mng.string_int_hash); hi; hi = apr_hash_next(hi)) {
            apr_hash_this(hi, &key, (apr_ssize_t *)&key_len, &val);
            fprintf(stderr, "%s --> %d\n", (char*)key, *(int*)val);
        }
    }else{
        int *val = (int *)apr_hash_get(data_mng.string_int_hash, key, strlen(key));
        if(val)
            fprintf(stderr, "%s --> %d\n", key, *(int *)val);
        else
            fprintf(stderr, "can`t find key %s \n", key);
    }
}

void test_add()
{
    int kk = 1 + 1;
    int vv = 2 + 2;
    int_int_hash_add(kk, vv);
    char *temp = "sfsdf";
    string_int_hash_add(temp, 5);
}

void test_select()
{
    int qk = 2;
    int_int_hash_select(qk, 0);
    string_int_hash_select("sfsdf", 0);
}

int main(int argc, char **argv)
{
    init_apr_lib();
    test_add();
    test_select();
    free_apr_lib();
    return 0;
}
