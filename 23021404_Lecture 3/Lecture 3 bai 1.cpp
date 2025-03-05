FUNCTION big_o_order(func)
    IF func == "2^10" THEN RETURN 0
    IF func == "logn" THEN RETURN 1
    IF func == "n" THEN RETURN 2
    IF func == "nlogn" THEN RETURN 3
    IF func == "n^2" THEN RETURN 4
    IF func == "n^3" THEN RETURN 5
    IF func == "2^n" THEN RETURN 6
    RETURN -1
END FUNCTION

FUNCTION main()
    DECLARE functions AS ARRAY = ["4nlogn + 2n", "2^10", "2^logn", "3n + 100logn", "4n", "2^n", "n^2 + 10n", "n^3", "nlogn"]
    DECLARE complexity AS ARRAY = ["nlogn", "2^10", "n", "n", "n", "2^n", "n^2", "n^3", "nlogn"]
    DECLARE size AS INTEGER = LENGTH OF functions

    FOR i FROM 1 TO size - 1 DO
        SET keyfunc = functions[i]
        SET keycomp = complexity[i]
        SET j = i - 1

        WHILE j >= 0 AND big_o_order(complexity[j]) > big_o_order(keycomp) DO
            SET functions[j + 1] = functions[j]
            SET complexity[j + 1] = complexity[j]
            DECREMENT j
        END WHILE

        SET functions[j + 1] = keyfunc
        SET complexity[j + 1] = keycomp
    END FOR

    FOR i FROM 0 TO size - 1 DO
        PRINT "O(" + functions[i] + ")"
    END FOR
END FUNCTION

