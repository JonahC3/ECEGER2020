.PHONY: clean All

All:
	@echo "----------Building project:[ Lab_1 - Debug ]----------"
	@cd "Lab_1" && "$(MAKE)" -f  "Lab_1.mk"
clean:
	@echo "----------Cleaning project:[ Lab_1 - Debug ]----------"
	@cd "Lab_1" && "$(MAKE)" -f  "Lab_1.mk" clean
