impl Solution {
    pub fn reverse_words(s: String) -> String {
        s.chars().rev().collect::<String>()
            .split(" ")
            .filter(|x| x.len() > 0)
            .map(|x| x.chars().rev().collect::<String>())
            .collect::<Vec<String>>()
            .join(" ")
    }
}