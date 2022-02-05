cmake_minimum_required(VERSION 3.17)
project(Jonny)

set(CMAKE_CXX_STANDARD 14)

add_executable(Jonny helloWorld.cpp)
#add_executable(Euler PracticeNCNA/eulers.cpp)
#add_executable(ProblemJ NCNARegional2020/ProblemJ.cpp)
#add_executable(ProblemK NCNARegional2020/ProblemK.cpp)
#add_executable(ProblemI NCNARegional2020/ProblemI.cpp)
#add_executable(ProblemD NCNARegional2020/ProblemD.cpp)
#add_executable(ProblemC NCNARegional2020/ProblemC.cpp)
#add_executable(ProblemF NCNARegional2020/ProblemF.cpp)
#add_executable(MitchellProbI ../Mitchell/NCNA2020Regional/ProblemI.cpp)
#add_executable(MitchellProbJ ../Mitchell/NCNA2020Regional/ProblemJ.cpp)
#add_executable(YouBeTheJudge NADC2021/YouBeTheJudge.cpp)

#add_executable(ProblemFPracticeNADC PracticeNADC/problemF.cpp)
#add_executable(ProblemIPracticeNADC PracticeNADC/problemI.cpp)
#add_executable(ProblemAPracticeNADC PracticeNADC/problemA.cpp)
#add_executable(ProblemGPracticeNADC PracticeNADC/problemG.cpp)
#add_executable(ProblemBPracticeNADC PracticeNADC/problemB.cpp)
#add_executable(ProblemKPracticeNADC PracticeNADC/problemK.cpp)

add_executable(2dRangeMinimumQuery NAPC2021/2dRangeMinimumQuery.cpp)

#add_executable(Shuffle NAPC2021/Day2Contest/Shuffle.cpp)
#add_executable(Squares NAPC2021/Day2Contest/Squares.cpp)
#add_executable(KnockoutRacing NAPC2021/Day2Contest/KnockoutRacing.cpp)
#add_executable(Eve NAPC2021/Day2Contest/Eve.cpp)
#add_executable(Commando NAPC2021/Day2Contest/Commando.cpp)
#add_executable(BinomialCoefficients NAPC2021/Day4Contest/BinomialCoefficients2.cpp)
#add_executable(Joke NAPC2021/Day4Contest/JokeWithPermutation.cpp)
#add_executable(ElementaryMath NAPC2021/Day4Contest/ElementaryMath2.cpp)

add_executable(Dinics ../LibraryCode/Graphs/DinicsAlgorithmMaxFlow.cpp)

add_executable(nsa_challenge NSAChallenge/nsa_challenge.cpp)

add_executable(YouBeTheJudgeAgain NAC2021/YouBeTheJudgeAgain.cpp)
add_executable(ThePaladin NAC2021/ThePaladin.cpp)
add_executable(ContestConstruction NAC2021/ContestConstruction.cpp)
add_executable(TravelLog NAC2021/TravelLog.cpp)
add_executable(CleaningRobot NAC2021/CleaningRobot.cpp)


