CONSTANT MAX_SIZE = 100
DECLARE heap AS ARRAY[MAX_SIZE]
DECLARE heapSize AS INTEGER = 0

FUNCTION swap(a, b)
    temp = a
    a = b
    b = temp
END FUNCTION

FUNCTION insert(value)
    IF heapSize >= MAX_SIZE THEN
        PRINT "Heap ð?y!"
        RETURN
    END IF

    heap[heapSize] = value
    i = heapSize
    INCREMENT heapSize

    WHILE i > 0 AND heap[i] < heap[(i - 1) / 2] DO
        swap(heap[i], heap[(i - 1) / 2])
        i = (i - 1) / 2
    END WHILE
END FUNCTION

FUNCTION deleteMin()
    IF heapSize == 0 THEN
        PRINT "Heap r?ng!"
        RETURN
    END IF

    heap[0] = heap[heapSize - 1]
    DECREMENT heapSize
    i = 0

    WHILE 2 * i + 1 < heapSize DO
        left = 2 * i + 1
        right = 2 * i + 2
        smallest = left

        IF right < heapSize AND heap[right] < heap[left] THEN
            smallest = right
        END IF

        IF heap[i] <= heap[smallest] THEN
            BREAK
        END IF

        swap(heap[i], heap[smallest])
        i = smallest
    END WHILE
END FUNCTION

FUNCTION printHeap()
    FOR i FROM 0 TO heapSize - 1 DO
        PRINT heap[i] + " "
    END FOR
    PRINT NEW_LINE
END FUNCTION

FUNCTION main()
    DECLARE elements AS ARRAY = {10, 14, 19, 26, 31, 42, 27, 44, 35, 33}
    
    FOR EACH num IN elements DO
        insert(num)
    END FOR

    PRINT "Min Heap ban dau: "
    printHeap()

    insert(8)
    PRINT "Sau khi them 8: "
    printHeap()

    deleteMin()
    PRINT "Sau khi xoa phan tu nho nhat: "
    printHeap()
END FUNCTION

