all:
	g++ BitBoard.cc test_pieces.cc 
clean:
	rm a.out core *gch
	# Cores might exist from purposely negative tests on asserts
