use std::collections::HashMap;

impl Solution {
    pub fn contains_duplicate(nums: Vec<i32>) -> bool {
        //let mut map: HashMap<&i32, bool> = HashMap::new();
        //           ^^^^^^^^^^^^^^^^^^^^^ no need to specify type
        let mut map = HashMap::new();
        for n in &nums { // not take ownership of nums Vec
            match map.get(n) {
                Some(x) => return true,
                None => map.insert(n, true),
            };
        }
        return false;
    }
}