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

// https://www.ign.com/faqs/2003/phantasy-star-online-episode-i-ii-section-id-faq-cube-394893
char* recommendations[] =
  { "Ranger"
  , "Ranger"
  , "Hunter"
  , "Hunter"
  , "Ranger"
  , "Force"
  , "Any"
  , "Hunter"
  , "Any"
  , "Hunter"
  };

// http://www.pso-world.com/sections.php?op=viewarticle&artid=452
char* common_drops[] =
  { "Shotguns (11%), Partisans (10%)"
  , "Rifles (13%), Daggers (10%)"
  , "Swords (13%), Rifles (10%)"
  , "Partisans (13%), Rods (10%)"
  , "Machineguns (13%), Daggers (10%)"
  , "Wands (13%), Partisans (10%)"
  , "Slicers (10%)"
  , "Daggers (13%)"
  , "None"
  , "Slicers (13%), Machineguns (10%)"
  };

char* rare_drops[] =
  { "Slicers (1%)"
  , "Swords (1%)"
  , "Machineguns (1%)"
  , "Wands (1%)"
  , "Swords (3%), Partisans (3%)"
  , "Rifles (1%)"
  , "Daggers (1%)"
  , "Rods (1%)"
  , "None"
  , "Shotguns (1%)"
  };

void print_usage( )
{
  printf( "Phantasy Star Online section ID calculator v1.0\n" );
  printf( "\n"                                                );
  printf( "Usage: pso-calc <name>\n"                          );
  printf( "\n"                                                );
}

void assert_name_valid( char* name )
{
  int i = 0;
  while( name[ i ] ) {
    if ( i == 12 ) {
      print_usage( );
      fprintf( stderr, "pso-calc error: name too long, names cannot be longer "
                       "than 12 characters\n" );
      exit( ERROR_NAME_TOO_LONG );
    }

    if ( name[ i ] < 32 || name[ i ] > 126 ) {
      print_usage( );
      fprintf( stderr, "pso-calc error: only ASCII characters allowed "
                       "in name\n" );
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
  if ( argc == 1 ) {
    print_usage( );
    fprintf( stderr, "pso-calc error: missing argument\n" );
    exit( ERROR_WRONG_NO_OF_ARGS );
  }

  if ( argc > 2 ) {
    print_usage( );
    fprintf( stderr, "pso-calc error: too many arguments, put names containing "
                     "spaces in quotes\n" );
    exit( ERROR_WRONG_NO_OF_ARGS );
  }

  assert_name_valid( argv[ 1 ] );

  int id = calculate_section_id( argv[ 1 ] );

  printf( "Section ID   : %d\n", id                    );
  printf( "Guild        : %s\n", guilds[ id ]          );
  printf( "Good for     : %s\n", recommendations[ id ] );
  printf( "Common drops : %s\n", common_drops[ id ]    );
  printf( "Rare drops   : %s\n", rare_drops[ id ]      );

  return 0;
}
