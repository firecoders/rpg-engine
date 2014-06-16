/* rpg-engine, An rpg engine written in C++
   Copyright (C) 2014 firecoders

   Permission is hereby granted, free of charge, to any person obtaining
   a copy of this software and associated documentation files (the "Software"),
   to deal in the Software without restriction, including without limitation
   the rights to use, copy, modify, merge, publish, distribute, sublicense,
   and/or sell copies of the Software, and to permit persons to whom the
   Software is furnished to do so, subject to the following conditions:

   The above copyright notice and this permission notice shall be included
   in all copies or substantial portions of the Software.

   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
   EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
   OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
   IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
   DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
   TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE
   OR THE USE OR OTHER DEALINGS IN THE SOFTWARE. */

#include "Draw_event_to_dict.h"

using namespace engine::converters;

Draw_event_to_dict::Draw_event_to_dict ( events::Listener< std::shared_ptr< types::Dict > >* listener ) :
    listener ( listener )
{}

void Draw_event_to_dict::handle_event ( std::shared_ptr < gui::Draw_event > draw_event )
{
    std::shared_ptr< engine::types::Dict > converted = std::make_shared< engine::types::Dict > ();
    converted->insert ( { std::string ( "type" ), std::string ( "converted engine::gui::Draw_event" ) } );
    converted->insert ( { std::string ( "rendertarget" ), draw_event->get_target () } );
    listener->handle_event ( converted );
}