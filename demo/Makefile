ENGINE_OBJS = pba.o ../dpif.o ../engine.o ../dot.o
FS_OBJS     = ${ENGINE_OBJS} ../fsMain.o ../fsCore.o

demo: demo.cgi demo2.cgi demo3.cgi demo4.cgi demo-reset.cgi demo5.cgi

fs-demo: ../dp.o ${ENGINE_OBJS} ../map.o
	gcc -o fs-demo ../dp.o ${ENGINE_OBJS} ../map.o

demo.cgi: ${ENGINE_OBJS} demo.o ../fsCore.o
	gcc -o demo.cgi ${ENGINE_OBJS} demo.o ../fsCore.o

demo2.cgi: demo2.o ${ENGINE_OBJS} ../fsCore.o
	gcc -o demo2.cgi demo2.o ${ENGINE_OBJS} ../fsCore.o

demo3.cgi: demo3.o ${ENGINE_OBJS} ../fsCore.o
	gcc -o demo3.cgi demo3.o ${ENGINE_OBJS} ../fsCore.o

demo4.cgi: demo4.o ${ENGINE_OBJS} ../fsCore.o
	gcc -o demo4.cgi demo4.o ${ENGINE_OBJS} ../fsCore.o

demo-reset.cgi: demo-reset.o ${ENGINE_OBJS} ../fsCore.o
	gcc -o demo-reset.cgi demo-reset.o ${ENGINE_OBJS} ../fsCore.o

demo5.cgi: demo5.o ${FS_OBJS}
	gcc -o demo5.cgi demo5.o ${FS_OBJS}


