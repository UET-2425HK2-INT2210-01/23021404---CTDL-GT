CLASS Node
    DATA data
    POINTER next

    FUNCTION Node(value)
        data = value
        next = NULL
    END FUNCTION
END CLASS

CLASS Stack
    PRIVATE:
        POINTER top

    FUNCTION Stack()
        top = NULL
    END FUNCTION

    FUNCTION push(value)
        CREATE newNode AS Node(value)
        newNode.next = top
        top = newNode
    END FUNCTION

    FUNCTION pop()
        IF top == NULL THEN
            PRINT "Stack is empty."
            RETURN
        END IF
        TEMP = top
        top = top.next
        DELETE TEMP
    END FUNCTION

    FUNCTION peek()
        IF top == NULL THEN
            PRINT "Stack is empty."
            RETURN -1
        END IF
        RETURN top.data
    END FUNCTION

    FUNCTION isEmpty()
        RETURN (top == NULL)
    END FUNCTION

    FUNCTION display()
        IF top == NULL THEN
            PRINT "Stack is empty."
            RETURN
        END IF
        TEMP = top
        PRINT "Stack: "
        WHILE TEMP != NULL DO
            PRINT TEMP.data, " "
            TEMP = TEMP.next
        END WHILE
        PRINT NEW_LINE
    END FUNCTION
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

    PRINT "Is stack empty? ", IF s.isEmpty() THEN "Yes" ELSE "No"
END FUNCTION

