" 增加类型关键字
syn keyword Type mapping string object  mixed varargs  fun 
" 增加语句关键字
syn keyword Statement foreach in switch case if
hi Statement ctermfg=98
" 类型设置黄色
hi Type ctermfg=yellow
" 定义LPC efunc
syn keyword lpcEfun intp classp mapp objectp stringp floatp sizeof undefinedp
" 设置efun着色
hi def lpcEfun ctermfg=magenta

" 函数高亮
syn match    cCustomParen    "(" contains=cParen
syn match    cCustomFunc     "\w\+\s*(" contains=cCustomParen

"hi def link cCustomFunc  Function
hi def cCustomFunc  ctermfg=green

