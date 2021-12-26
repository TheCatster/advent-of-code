package days

import InputReader

object Day7 {

    fun partOne() {
        /*Work below.*/
        println(countGoldBags(createPartOneRuleMap(createRulesList())))
    }

    fun partTwo() {
        /*Heck with this, I answered it in Python. I'll come back to this eventually.*/
        val bagRules = createPartTwoRuleMap(createRulesList())
        println(bagRules)

    }

    private fun createRulesList(): MutableList<MutableList<String>> {
        val dataList = InputReader.getInputAsList(7)

        val rulesList = mutableListOf<MutableList<String>>()
        val emptyList = mutableListOf("", " ", "\n", "\n\n", ".", "  ", ",")
        val bagRegex = "bags|bag|contains|contain".toRegex()

        for (x in dataList) {
            val y = mutableListOf<String>()
            for (z in x.split(bagRegex).toMutableList()) {
                if (z in emptyList) {
                    continue
                }
                y.add(z.replace(",", "").trim())
            }
            rulesList.add(y)
        }

        return rulesList
    }

    private fun createPartOneRuleMap(rules: MutableList<MutableList<String>>): MutableMap<String, MutableList<String>> {
        val numberRegex = "\\d*".toRegex()
        val bagRule = mutableMapOf<String, MutableList<String>>()

        for (x in rules) {
            val outerColor = x[0]
            val bagContains = mutableListOf<String>()
            for (y in x) {
                bagContains.add(y.replace(numberRegex, "").trim())
            }
            bagRule[outerColor] = bagContains
        }

        return bagRule
    }

    private fun createPartTwoRuleMap(rules: MutableList<MutableList<String>>): MutableMap<String, MutableList<MutableMap<String, Int>>> {
        val numberRegex = "\\d*".toRegex()
        val bagRule = mutableMapOf<String, MutableList<MutableMap<String,Int>>>()

        for (x in rules) {
            val outerColor = x[0]
            val bagContains = mutableListOf<MutableMap<String,Int>>()
            for (y in x) {
                bagContains.add(mutableMapOf(y.trim().split(" ")[1] to y.trim().split(" ")[0].toInt()  ))
            }
            bagRule[outerColor] = bagContains
        }

        return bagRule
    }

    private fun countGoldBags(bagRules: MutableMap<String, MutableList<String>>): Int {
        val STARTING_COLOR = "shiny gold"
        val possibleContainers = mutableSetOf<String>()

        bagRules.forEach { (k, v) ->
            if (STARTING_COLOR in v) {
                possibleContainers.add(k)
            }
        }

        var foundNew = true
        while (foundNew) {
            foundNew = false
            for (value in possibleContainers.toMutableSet()) {
                bagRules.forEach { (k, v) ->
                    if (value in v) {
                        if (k !in possibleContainers.toMutableSet()) {
                            foundNew = true
                            possibleContainers.add(k)
                        }
                    }
                }
            }
        }

        return possibleContainers.size - 1
    }
}
