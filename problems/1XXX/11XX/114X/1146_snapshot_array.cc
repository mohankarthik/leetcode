#include "../../../../common/Includes.h"

class SnapshotArray {
private:
    unordered_map<int,map<int,int>> snapshots;
    int length = 0;
    int current_snap = 0;
public:
    SnapshotArray(int length) {
        this->length = length;
    }
    
    void set(int index, int val) {
        assert(index >= 0 and index <= length);
        snapshots[index][current_snap] = val;
    }
    
    int snap() {
        current_snap++;
        return current_snap - 1;
    }
    
    int get(int index, int snap_id) {
        auto it = snapshots[index].upper_bound(snap_id);
        return it == snapshots[index].begin() ? 0 : prev(it)->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */

int main (void) {
    SnapshotArray *snap = new SnapshotArray(1);
    snap->set(0, 15);
    assert(snap->snap() == 0);
    assert(snap->snap() == 1);
    assert(snap->snap() == 2);
    assert(snap->get(0, 2) == 15);
    assert(snap->snap() == 3);
    assert(snap->snap() == 4);
    assert(snap->get(0, 0) == 15);
}