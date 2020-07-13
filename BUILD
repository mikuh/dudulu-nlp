cc_library(
    name = "text_normalize",
    srcs = ["core/text_normalize.cc"],
    hdrs = ["core/text_normalize.h"],
    deps = [":utils"],
)

cc_library(
    name = "text_tokenizer",
    srcs = ["core/text_tokenizer.cc"],
    hdrs = ["core/text_tokenizer.h"],
    deps = [":utils"],
)


cc_library(
    name = "utils",
    srcs = ["utils/utils.cc"],
    hdrs = ["utils/utils.h"],
)


cc_binary(
    name = "test",
    srcs = ["test.cc"],
    deps = [":text_normalize", ":text_tokenizer"],
)