import java.util.*

fun main() {
    val br = System.`in`.bufferedReader()
    val s = br.readLine()!!

    var flag = true
    var idx = 0
    while (flag && idx < s.length) {
        if(idx < s.length - 1 && s[idx] == 'p' && s[idx+1] == 'i') idx += 2
        else if(idx < s.length - 1 && s[idx] == 'k' && s[idx+1] == 'a') idx += 2
        else if(idx < s.length - 2 && s[idx] == 'c' && s[idx+1] == 'h' && s[idx+2] == 'u') idx += 3
        else flag = false
    }
    if(flag) println("YES") else println("NO")
}