CLASS Node
    INTEGER data
    Node next

    CONSTRUCTOR(val)
        data = val
        next = NULL
    END CONSTRUCTOR
END CLASS

CLASS Queue
    Node front, rear

    CONSTRUCTOR()
        front = NULL
        rear = NULL
    END CONSTRUCTOR

    FUNCTION enqueue(value)
        newNode = NEW Node(value)
        IF rear IS NULL THEN
            front = rear = newNode
            RETURN
        END IF
        rear.next = newNode
        rear = newNode
    END FUNCTION

    FUNCTION dequeue()
        IF front IS NULL THEN
            PRINT "Queue is empty."
            RETURN
        END IF
        temp = front
        front = front.next
        IF front IS NULL THEN
            rear = NULL
        END IF
        DELETE temp
    END FUNCTION

    FUNCTION getFront()
        IF front IS NULL THEN
            PRINT "Queue is empty."
            RETURN -1
        END IF
        RETURN front.data
    END FUNCTION

    FUNCTION isEmpty()
        RETURN front IS NULL
    END FUNCTION

    FUNCTION display()
        IF front IS NULL THEN
            PRINT "Queue is empty."
            RETURN
        END IF
        temp = front
        PRINT "Queue: "
        WHILE temp IS NOT NULL DO
            PRINT temp.data, " "
            temp = temp.next
        END WHILE
        PRINT NEW_LINE
    END FUNCTION
END CLASS

FUNCTION main()
    DECLARE q AS Queue
    CALL q.enqueue(10)
    CALL q.enqueue(20)
    CALL q.enqueue(30)
    CALL q.display()

    PRINT "Front: ", q.getFront()

    CALL q.dequeue()
    CALL q.display()

    CALL q.dequeue()
    CALL q.dequeue()
    CALL q.dequeue()

    PRINT "Queue empty? ", IF q.isEmpty() THEN "Yes" ELSE "No"
END FUNCTION

