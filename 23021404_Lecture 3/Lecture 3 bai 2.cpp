FUNCTION power_iterative(n)
    SET result = 1
    SET exponent = ABS(n)
    
    FOR i FROM 0 TO exponent - 1 DO
        SET result = result * 2
    END FOR
    
    IF n < 0 THEN
        RETURN 1.0 / result
    END IF
    
    RETURN result
END FUNCTION

FUNCTION power_recursive(n)
    IF n == 0 THEN RETURN 1
    ELSE IF n > 0 THEN RETURN 2 * power_recursive(n - 1)
    ELSE RETURN 1.0 / power_recursive(-n)
    END IF
END FUNCTION

FUNCTION power_divide_conquer(n)
    IF n == 0 THEN RETURN 1
    
    IF n < 0 THEN RETURN 1.0 / power_divide_conquer(-n)
    
    SET half = power_divide_conquer(n / 2)
    
    IF n MOD 2 == 0 THEN RETURN half * half
    ELSE RETURN half * half * 2
    END IF
END FUNCTION

FUNCTION main()
    READ n
    
    PRINT "2^" + n + " (Iterative): " + power_iterative(n)
    PRINT "2^" + n + " (Recursive): " + power_recursive(n)
    PRINT "2^" + n + " (Divide & Conquer): " + power_divide_conquer(n)
END FUNCTION

