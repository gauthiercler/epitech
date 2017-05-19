add_executable(Tests

        TRUEtest.cpp
        FALSEtest.cpp
        INPUTtest.cpp
        OUTPUTtest.cpp
        PINtest.cpp
        COMPUTE_LISTtest.cpp
        ANDtest.cpp
        NANDtest.cpp
        ORtest.cpp
        NORtest.cpp
        XORtest.cpp
        C4081test.cpp
        NOTtest.cpp
        FOURBITADDERtest.cpp
        DFLIPFLOPtest.cpp

        ../sources/classes/components/True.cpp
        ../sources/classes/components/False.cpp
        ../sources/classes/components/INPUT.cpp
        ../sources/classes/components/OUTPUT.cpp

        ../sources/classes/Pin.cpp
        ../sources/classes/AComponent.cpp

        ../sources/classes/components/gates/AND.cpp
        ../sources/classes/components/gates/NAND.cpp
        ../sources/classes/components/gates/OR.cpp
        ../sources/classes/components/gates/NOR.cpp
        ../sources/classes/components/gates/XOR.cpp
        ../sources/classes/components/C4081.cpp
        ../sources/classes/components/gates/NOT.cpp
        ../sources/classes/components/C4081.cpp
        ../sources/classes/components/FULL_ADDER.cpp
        ../sources/classes/components/C4008.cpp
        ../sources/classes/components/D_FLIP_FLOP.cpp
        ../sources/classes/components/C4013.cpp
        ../sources/classes/components/CLOCK.cpp)

target_link_libraries(Tests
        GTest::GTest
        GTest::Main)