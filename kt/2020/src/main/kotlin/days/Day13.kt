package days

import InputReader
import kotlin.reflect.typeOf

object Day13 {

    val dataList = InputReader.getInputAsList(13)

    fun partOne() {
        /**/
        val earliestTime = dataList[0].toInt()
        val preBusIDs = dataList[1].split(",").toMutableList()
        preBusIDs.removeAll { e -> e == "x" }
        val busIDs = preBusIDs.map { it.toInt() }.toMutableList()

        println(earliestTime)
        println(busIDs)
        var fastestDeparture = Int.MAX_VALUE
        var fastestBusID = 0
        for (id in busIDs) {
            var time = id
            while (time < earliestTime) {
                time *= 2
            }
            time *= 2
            println("$id : $time")
            if (fastestDeparture > time) {
                fastestDeparture = time - earliestTime
                fastestBusID = id
            }
        }
        println(fastestDeparture*fastestBusID)
    }

    fun partTwo() {
        /**/

    }
}
