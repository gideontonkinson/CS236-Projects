cmake_minimum_required(VERSION 3.16)
project(Project_1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Project_1
    Automaton.h
    ColonAutomaton.cpp
    ColonAutomaton.h
    ColonDashAutomaton.cpp
    ColonDashAutomaton.h
    Lexer.cpp
    Lexer.h
    main.cpp
    Token.cpp
    Token.h
    CommaAutomaton.cpp
    CommaAutomaton.h
    PeriodAutomaton.cpp
    PeriodAutomaton.h
    QMarkAutomaton.cpp
    QMarkAutomaton.h
    LeftParenAutomaton.cpp
    LeftParenAutomaton.h
    RightParenAutomaton.cpp
    RightParenAutomaton.h
    MultiplyAutomaton.cpp
    MultiplyAutomaton.h
    AddAutomaton.cpp
    AddAutomaton.h
    SchemesAutomaton.cpp
    SchemesAutomaton.h
    FactAutomaton.cpp
    FactAutomaton.h
    RulesAutomaton.cpp
    RulesAutomaton.h
    QueriesAutomaton.cpp
    QueriesAutomaton.h
    IDAutomaton.cpp
    IDAutomaton.h
    StringAutomaton.cpp
    StringAutomaton.h
    CommentAutomation.cpp
    CommentAutomation.h EOFAutomaton.cpp EOFAutomaton.h UndefinedAutomata.cpp UndefinedAutomata.h)
