#include "test.h"
#include "../src/queue.h"

int ptr_cmp(void* d1, void* d2) {
    if(d1 == d2) {
        return 0;
    }
    return -1;
}
int int_cmp(void* d1, void* d2) {
    if( *(int*)d1 == *(int*)d2) {
        return 0;
    }
    return -1;
}

int main() {
    
    queue_t q;
    
    init_queue(&q);
    assert(q.rear == NULL, "q rear should be null");
    assert(qexists(&q, NULL, &int_cmp) == 0, "qexists should return 0 on null queue");
    int i1 = 50;
    qenqueue(&q, &i1);
    assert(q.size == 1, "q size should be 1 after enqueue");
    int i2 = 10;
    qenqueue(&q, &i2);
    assert(q.size == 2, "queue size should be 2 after enqueue");
    assert(q.rear->next->next->data == &i2, "rear next next should be equal to the last item added");
    assert(qexists(&q, &i2, &ptr_cmp) == 1, "2nd item in q should exist");
    assert(qexists(&q, NULL, &ptr_cmp) == 0, "qexists of null should be false");
    int* i3;
    qdequeue(&q, (void**)&i3);
    assert(i3 == &i1, "data on dequeue should be equal to i1");
    assert(q.size == 1, "q size should decrease after dequeue");
    
    qdequeue(&q, (void**)&i3);
    assert(i3 == &i2, "2nd dequeue should return 2nd item");
    assert(q.size == 0, "q size after 2nd dequeue is 0");

    int is[5] = {1, 2, 3, 4, 5};
    qenqueue(&q, &(is[0]));
    qenqueue(&q, &(is[1]));
    qenqueue(&q, &(is[2]));
    qenqueue(&q, &(is[3]));
    qenqueue(&q, &(is[4]));
    assert(q.size == 5, "size after 5 enqueue is 5");
    int s = 3;
    int* plc;
    qdelete_item(&q, &s, (void**)&plc, &int_cmp);
    assert(q.size == 4, "size after delete item is 4 and all");
    assert(qexists(&q, &(is[0]), &ptr_cmp) == 1, "q item 1 should exist after delete");
    assert(qexists(&q, &(is[1]), &ptr_cmp) == 1, "q item 2 should exist after delete");
    assert(qexists(&q, &(is[3]), &ptr_cmp) == 1, "q item 3 should exist after delete");
    assert(qexists(&q, &(is[4]), &ptr_cmp) == 1, "q item 4 should exist after delete");

    finish();

}