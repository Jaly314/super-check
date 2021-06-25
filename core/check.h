
#define RAW     0
#define ASSERT  1
#define ERROR   2
#define WARN    3         
#define INFO    4         
#define DEBUG   5    

#define TRUE	1
#define FALSE	0

/*!
 *	key API for user
 *	eg: LOG(INFO, "xxx %d\n", dat);
 *		LOG(ERROR, "xxx",xxx,x,x,x,x);
 */
#undef  LOG /* ignore compile warnning */
#define LOG(lvl, ...)   if(lvl < INFO) {printf("[%s:%d]", __FUNCTION__, __LINE__);printf(__VA_ARGS__);} 

 /*!
  *  Super Check
  *  LOG   中带行号，文件名；
  *  stat  待校验的值，一般函数返回值。
  *  tar   期望值, 一般用对应宏。
  *  expr  处理表达式， 如果只是报错不处理，可以用 DO_NOTHING
  *  ...   扩充表达式，可有可无
  */
#undef CHECK
#define CHECK(exp, tar, expr, ...)                          \
        {                                                   \
            unsigned int _ret = (unsigned int)(exp);	      	\
            if(_ret != (unsigned int)(tar))			            		\
            {                                               \
                LOG(ERROR, "[%s] (%u) != (%u) cause err \n", #exp, _ret, (unsigned int)tar);  \
                expr;                                       \
                __VA_ARGS__;                                \
            }                                               \
        }


#define DO_NOTHING ;            /* 无操作 */
