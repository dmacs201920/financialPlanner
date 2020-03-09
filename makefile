c=gcc
link_flags=-o
compile_flags=-c
FinancialPlanner:FinancialPlanner.o FinancialPlannerFunctions.o
	$(c) -g  $(link_flags)   $@ FinancialPlanner.o FinancialPlannerFunctions.o -lncurses -lm
FinancialPlanner.o FinancialPlannerFunctions.o: FinancialPlanner.c FinancialPlannerFunctions.c                                                   header.h
	$(c) $(compile_flags) $ *.c
clean:
	rm -f *.o FinancialPlanner
