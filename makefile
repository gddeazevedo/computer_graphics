OUTPUT=out/a.out

compile:
	gcc $(file) -lglut -lGL -lGLU -lm -o $(OUTPUT)

run:
	./$(OUTPUT)
