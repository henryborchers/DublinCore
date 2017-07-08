if (DOXYGEN_FOUND)
    function(build_HTML_docs)
        doxygen_add_docs(DublinCoreDocsHTML
                ${CMAKE_CURRENT_SOURCE_DIR}/src
                COMMENT "Generate html docs")
        add_dependencies(DublinCore DublinCoreDocsHTML)
    endfunction()

    function(build_MAN_docs)
        set(DOXYGEN_GENERATE_HTML NO)
        set(DOXYGEN_GENERATE_MAN YES)
        doxygen_add_docs(DublinCoreDocsMAN
                ${CMAKE_CURRENT_SOURCE_DIR}/src
                COMMENT "Generate MAN page docs")
        add_dependencies(DublinCore DublinCoreDocsMAN)
    endfunction()

    function(build_RTF_docs)
        set(DOXYGEN_GENERATE_RTF YES)
        set(DOXYGEN_GENERATE_HTML NO)
        doxygen_add_docs(DublinCoreDocsRTF
                ${CMAKE_CURRENT_SOURCE_DIR}/src
                COMMENT "Generate RTF page docs")
        add_dependencies(DublinCore DublinCoreDocsRTF)
    endfunction()

    function(build_LATEX_docs)
        set(DOXYGEN_GENERATE_LATEX YES)
        set(DOXYGEN_GENERATE_HTML NO)
        doxygen_add_docs(DublinCoreDocsLATEX
                ${CMAKE_CURRENT_SOURCE_DIR}/src
                COMMENT "Generate LATEX page docs")
        add_dependencies(DublinCore DublinCoreDocsLATEX)
    endfunction()
endif ()