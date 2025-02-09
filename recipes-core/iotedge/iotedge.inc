DEPENDS += "openssl aziotctl"

export OPENSSL_DIR = "${STAGING_EXECPREFIXDIR}"
export LIBIOTHSM_NOBUILD="On"

SRC_URI +="file://0001-Change-panic-strategy-to-unwind.patch \
 file://0002-Fix-aziot-dependencies.patch"

do_install () {
    # Binaries
    install -d  "${D}${bindir}"
    install -m 755 "${WORKDIR}/build/target/${RUST_TARGET_SYS}/release/iotedge" ${D}${bindir}/iotedge
}