class Solution {
    fun solution(s: String): String = s.toLowerCase().split(" ").map { it.capitalize() }.joinToString(" ")
}