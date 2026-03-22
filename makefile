OUTPUT=out/a.out

compile:
	gcc $(file) -lglut -lGL -lGLU -lm -o $(OUTPUT)

compile++:
	g++ $(file) -lglut -lGL -lGLU -lm -o $(OUTPUT)

run:
	./$(OUTPUT)

exec: compile run
exec++: compile++ run