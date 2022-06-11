.PHONY: clean All

All:
	@echo "----------Building project:[ heuristica_teste - Debug ]----------"
	@cd "heuristica_teste" && "$(MAKE)" -f  "heuristica_teste.mk"
clean:
	@echo "----------Cleaning project:[ heuristica_teste - Debug ]----------"
	@cd "heuristica_teste" && "$(MAKE)" -f  "heuristica_teste.mk" clean
