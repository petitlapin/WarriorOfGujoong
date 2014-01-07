#include <QDomElement>
#include <QString>
#include <map>
#include <vector>
#include "core/map_data/tiledata.hpp"
#include "modelarea.h"

using namespace std;

ModelArea::ModelArea(QDomElement & elt , map < QString, QSharedPointer<TileData> > &tiles_map )
{
    if ( elt.tagName() == "area" && elt.hasAttribute("width") && elt.hasAttribute("height") )
    {
        // Creating tiles_grid
        this->tiles_grid.resize(QString(elt.attribute("width")).toInt());
        int height = QString(elt.attribute("height")).toInt();
        for ( unsigned int i = 0 ; i < this->tiles_grid.size() ; i ++ )
        {
            this->tiles_grid.at(i).resize(height);
        }

        // Filling tiles_grid
        QDomElement child=elt.firstChild().toElement();
        while(!child.isNull())
        {
            if ( child.tagName() == "position" && child.hasAttribute("x") && child.hasAttribute("y") && child.hasAttribute("tileId") )
            {
                int x = QString(child.attribute("x")).toInt();
                int y = QString(child.attribute("y")).toInt();
                QSharedPointer<TileData> tile ( tiles_map[child.attribute("tileId")] );
                this->tiles_grid.at(x).at(y)  = QSharedPointer<TileData>(new TileData(*tile));
            }
            child = child.nextSibling().toElement();
        }
    }


}


int ModelArea::get_width () const
{
    return this->tiles_grid.size();
}

int ModelArea::get_height () const
{

    return this->tiles_grid.size() == 0 ? 0 : this->tiles_grid.at(0).size();
}

vector<vector<QSharedPointer<TileData> > > &ModelArea::get_tiles_grid()
{
    return this->tiles_grid;
}

void ModelArea::set_tiles_walkable_for_action(QList<QPair<int, int> > &non_walkable_points)
{
    for (size_t i = 0 ; i < tiles_grid.size() ; ++ i) {
        for (size_t j = 0 ; j < tiles_grid[i].size() ; ++ j) {
            (*tiles_grid[i][j]).set_walkable_for_action(true);
        }
    }

    for(QList<QPair<int, int> >::iterator it = non_walkable_points.begin() ; it != non_walkable_points.end() ; ++ it) {
        (*tiles_grid[(*it).first][(*it).second]).set_walkable_for_action(false);
    }
}
