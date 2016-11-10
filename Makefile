OBJ = 
src = $(OBJ:.o=.cxx)

EXE = 

FLAGS = -Wall -O3 --std=c++11
cc = g++
# all libs including root libs

$(EXE) : $(OBJ)
	$(cc) $(FLAGS) -o $(EXE) $^  

-include $(object:.o=.d)

$(OBJ) : $(src)
	$(cc) $(FLAGS) -o $(@) -c $(@:.o=.cxx)
	$(cc) $(FLAGS) -o $(@:.o=.d) -MM $(@:.o=.cxx)

clean:
	rm -f $(OBJ) $(OBJ:.o=.d) $(EXE) *~ 
