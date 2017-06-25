//
// Created by Borchers, Henry Samuel on 6/24/17.
//

#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "DublinCore.h"


TEST_CASE("Element", "[Element]") {
    Element contributor;

    SECTION("Assign the element directly") {
        contributor.setKey("contributor");
        contributor.setValue("Henry");
        REQUIRE(contributor.getValue() == "Henry");
        REQUIRE(contributor.getKey() == "contributor");
    }
}

TEST_CASE("Root", "[Root]") {
    Root root;

    SECTION("Create a default root") {

        REQUIRE(root.getName() == "root");
    }

    SECTION("Create a root and change it to Person") {
        root.setName("Person");
        REQUIRE(root.getName() == "Person");
    }

    SECTION("Add a contributor tag to a default root") {
        Element contributor;

        contributor.setKey("contributor");
        contributor.setValue("Henry");
        root.setElement(contributor);

        Element res = root.getElement("contributor");
        REQUIRE(res.getKey() == contributor.getKey());
        REQUIRE(res.getValue() == contributor.getValue());

    }

    SECTION("Add a contributor tag to a default root without adding a Element first") {

        root.setElement("contributor", "Henry");
        Element res = root.getElement("contributor");
        REQUIRE(res.getKey() == "contributor");
        REQUIRE(res.getValue() == "Henry");
    }

}

TEST_CASE("Printer", "[Printer]") {
    Printer p;
    Root root;

    SECTION("Create a XML string from the root") {

        root.setElement("contributor", "Henry");
        root.setElement("date", "January 19, 1985");

        REQUIRE(p.print(root) == "<root><contributor>Henry</contributor><date>January 19, 1985</date></root>");
    }


}