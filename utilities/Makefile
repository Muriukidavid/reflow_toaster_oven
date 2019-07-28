all: genrgb genpwm clean

gamma: 
	@echo 'Building gamma values generating binary'
	@echo '---------------------------------------'
	gcc -o gamma generateGamma.c -lm
genpwm: gamma
	@echo 'Generating gamma values array'
	@echo '-----------------------------'
	./gamma 1.8 100 
genrgb: gamma
	@echo 'Generating gamma values array'
	@echo '-----------------------------'
	./gamma 2.2 255
clean:
	@echo 'removing gamma values generating binary'
	@echo '---------------------------------------'
	$(RM) gamma

.PHONY: all gamma

