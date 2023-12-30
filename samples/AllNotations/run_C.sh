export ASTAH_HOME=~/ClasHStamP/astah-com_linux
export TOOL_DIR=~/ClasHStamP/release
export PROJECT=~/ClasHStamP/samples/AllNotations/Design.asta
export EXT_CODE_OPT=y
export ENCODING=UTF-8
export JAVA_TOOL_OPTIONS=-Dfile.encoding=UTF-8

export BAT_DIR=~/ClasHStamP
export BIN_DIR=$BAT_DIR/release/ClasHStamP.jar
export LIB_DIR=$BAT_DIR/lib

export ASTAH_COM_JAR=$ASTAH_HOME/astah-community.jar
export ASTAH_UML_JAR=$ASTAH_HOME/astah-uml.jar
export ASTAH_PRO_JAR=$ASTAH_HOME/astah-pro.jar
export ASTAH_JAR=$ASTAH_COM_JAR:$ASTAH_UML_JAR:$ASTAH_PRO_JAR
export API_JAR=$ASTAH_HOME/astah-api.jar

export CSV_JAR=$LIB_DIR/commons-csv-1.1.jar
export LOG_JAR=$LIB_DIR/logback-loader-1.0.9b.jar
export SLF_JAR=$LIB_DIR/slf4j-api-1.6.6.jar

export CLASSPATH=$BIN_DIR:$ASTAH_JAR:$API_JAR:$CSV_JAR:$LOG_JAR:$SLF_JAR

export INITIAL_HEAP_SIZE=16m
export MAXIMUM_HEAP_SIZE=256m

export JAVA_OPTS="-Xms$INITIAL_HEAP_SIZE -Xmx$MAXIMUM_HEAP_SIZE"
export JAVA_OPTS="$JAVA_OPTS -classpath $CLASSPATH"

export SAMPLE_HOME=`dirname $0`
export OUTPUT=$SAMPLE_HOME/C

export LANGUAGE=c
export SYNTAX=$TOOL_DIR/Syntax_CNew.csv
export SYNTAX_ABSTRACT=$TOOL_DIR/Syntax_CNew.csv
export SYNTAX_INTERFACE=$TOOL_DIR/Syntax_CNew.csv
export SYNTAX_BASECLASS=$TOOL_DIR/Syntax_CNew.csv

export PACKAGE=Model
java $JAVA_OPTS stm.TMain %1 %2

export PACKAGE=Abstracts
java $JAVA_OPTS stm.TMain %1 %2

export PACKAGE=NonOOP
java $JAVA_OPTS stm.TMain %1 %2

export LANGUAGE=h
export SYNTAX=$TOOL_DIR/Syntax_HNew.csv
export SYNTAX_ABSTRACT=$TOOL_DIR/Syntax_HNew.csv
export SYNTAX_INTERFACE=$TOOL_DIR/Syntax_HNew.csv
export SYNTAX_BASECLASS=$TOOL_DIR/Syntax_HNew.csv

export PACKAGE=Model
java $JAVA_OPTS stm.TMain %1 %2

export PACKAGE=Interfaces
java $JAVA_OPTS stm.TMain %1 %2

export PACKAGE=Abstracts
java $JAVA_OPTS stm.TMain %1 %2

export PACKAGE=NonOOP
java $JAVA_OPTS stm.TMain %1 %2
