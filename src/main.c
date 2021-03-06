#include <stdio.h>
#include <stdlib.h>

#define ERROR_NAME_TOO_LONG    1
#define ERROR_INVALID_CHAR     2
#define ERROR_WRONG_NO_OF_ARGS 3

char* guilds[] =
  { "Viridia"
  , "Greenill"
  , "Skyly"
  , "Bluefull"
  , "Purplenum"
  , "Pinkal"
  , "Redria"
  , "Oran"
  , "Yellowboze"
  , "Whitill"
  };

void print_usage( )
{
  printf( "placeholder\n" );
}

void assert_name_valid( char* name )
{
  int i = 0;
  while( name[ i ] ) {
    if ( i == 12 ) {
      fprintf( stderr, "Name too long\n" );
      exit( ERROR_NAME_TOO_LONG );
    }

    if ( name[ i ] < 32 || name[ i ] > 126 ) {
      fprintf( stderr, "Invalid character: %c\n", name[ i ] );
      exit( ERROR_INVALID_CHAR );
    }
    i++;
  }
}

int calculate_section_id( char* name )
{
  int id = 0;

  for( int i = 0; name[ i ]; i++ ) {
    id += name[ i ];
  }

  id %= 10;

  return id;
}

int main( int argc, char **argv )
{
  if ( argc != 2 ) {
    print_usage( );
    exit( ERROR_WRONG_NO_OF_ARGS );
  }

  assert_name_valid( argv[ 1 ] );

  int id = calculate_section_id( argv[ 1 ] );

  printf( "Section id: %d\n", id );
  printf( "Guild     : %s\n", guilds[ id ] );

  return 0;
}
