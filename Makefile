.PHONY: clean All

All:
	@echo "----------Building project:[ Lab_2 - Debug ]----------"
	@cd "Lab_2" && "$(MAKE)" -f  "Lab_2.mk"
clean:
	@echo "----------Cleaning project:[ Lab_2 - Debug ]----------"
	@cd "Lab_2" && "$(MAKE)" -f  "Lab_2.mk" clean
