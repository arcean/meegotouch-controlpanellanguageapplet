#!/bin/sh

langdata=$(gconftool -g /meegotouch/i18n/language)
# default
langid=en_US.UTF-8

if [ -n $langdata ]; then
    # remove everything after a @ including the @ itself because
    # the options after @ in libicu locale names like 
    # zh_CN@collation=stroke do not make sense for the POSIX locales:
    langid=${langdata%%@*}
    # some conversion needs from libicu ids to posix ids
    if [ "$langid" == "en" ]; then
        langid=en_GB
    elif [ "$langid" == "zh" ]; then
        langid=zh_CN
    elif [ "$langid" == "es_419" ]; then
        langid="es_MX"
    fi
fi
unset LC_ALL
export LANG=$langid
