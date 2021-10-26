cmake_minimum_required(VERSION 3.16)
project(Project_3)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Project_2
        AddAutomaton.cpp
        AddAutomaton.h
        Automaton.h
        ColonAutomaton.cpp
        ColonAutomaton.h
        ColonDashAutomaton.cpp
        ColonDashAutomaton.h
        CommaAutomaton.cpp
        CommaAutomaton.h
        CommentAutomation.cpp
        CommentAutomation.h
        EOFAutomaton.cpp
        EOFAutomaton.h
        FactAutomaton.cpp
        FactAutomaton.h
        IDAutomaton.cpp
        IDAutomaton.h
        LeftParenAutomaton.cpp
        LeftParenAutomaton.h
        Lexer.cpp
        Lexer.h
        main.cpp
        MultiplyAutomaton.cpp
        MultiplyAutomaton.h
        PeriodAutomaton.cpp
        PeriodAutomaton.h
        QMarkAutomaton.cpp
        QMarkAutomaton.h
        QueriesAutomaton.cpp
        QueriesAutomaton.h
        RightParenAutomaton.cpp
        RightParenAutomaton.h
        RulesAutomaton.cpp
        RulesAutomaton.h
        SchemesAutomaton.cpp
        SchemesAutomaton.h
        StringAutomaton.cpp
        StringAutomaton.h
        Token.cpp
        Token.h
        UndefinedAutomata.cpp
        UndefinedAutomata.h Parser.cpp Parser.h Predicate.cpp Predicate.h Parameter.cpp Parameter.h Rule.cpp Rule.h DatalogProgram.cpp DatalogProgram.h Tuple.cpp Tuple.h Header.cpp Header.h Relation.cpp Relation.h)
