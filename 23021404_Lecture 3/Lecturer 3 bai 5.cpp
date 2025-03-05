DEFINE MAX = 100

CLASS Stack
    PRIVATE:
        INTEGER top
        INTEGER arr[MAX]

    CONSTRUCTOR()
        top = -1

    FUNCTION isEmpty()
        RETURN (top == -1)

    FUNCTION isFull()
        RETURN (top == MAX - 1)

    FUNCTION push(value)
        IF isFull() THEN
            PRINT "Stack overflow! Cannot push ", value
            RETURN
        END IF
        top = top + 1
        arr[top] = value

    FUNCTION pop()
        IF isEmpty() THEN
            PRINT "Stack underflow! Cannot pop."
            RETURN
        END IF
        top = top - 1

    FUNCTION peek()
        IF isEmpty() THEN
            PRINT "Stack is empty."
            RETURN -1
        END IF
        RETURN arr[top]

    FUNCTION display()
        IF isEmpty() THEN
            PRINT "Stack is empty."
            RETURN
        END IF
        PRINT "Stack: "
        FOR i = top DOWNTO 0 DO
            PRINT arr[i], " "
        END FOR
        PRINT NEW_LINE
END CLASS

FUNCTION main()
    DECLARE s AS Stack
    CALL s.push(10)
    CALL s.push(20)
    CALL s.push(30)
    CALL s.display()

    PRINT "Top element: ", s.peek()

    CALL s.pop()
    CALL s.display()
    CALL s.pop()
    CALL s.pop()
    CALL s.pop()

    PRINT "Stack empty? ", IF s.isEmpty() THEN "Yes" ELSE "No"
END FUNCTION

