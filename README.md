# super-check
-------------

Super check, make your code more interesting and easier。
偶是中国人，不说鸟话！

见过很多类似的写法，就连鼎鼎大名的GLib对此的实现，都很渣。do_val_if_fail(xxxx); 看似一眼知其意，但是非常苦涩，扩展性不好，而且很长，一行80个字符很容易就超了，实际使用时体验非常糟糕。

以下是我的实现版本：

```c
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

```

可以使用demo体验以下，见utils测试代码。
