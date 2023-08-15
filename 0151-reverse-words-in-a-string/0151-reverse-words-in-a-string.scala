object Solution {
    def reverseWords(s: String): String = {
        s.reverse
            .split(" ")
            .filter(x => x.size > 0)
            .map(x => x.reverse)
            .mkString(" ")
    }
}